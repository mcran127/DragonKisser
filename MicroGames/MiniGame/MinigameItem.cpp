// Copyright Brigham Young University. All Rights Reserved.


#include "MinigameItem.h"

#include "DragonKisserST2/Characters/Domingo/DomingoBase.h"
#include "DragonKisserST2/Global/Control/ControlHUD.h"
#include "DragonKisserST2/Global/Control/DragonKisserST2GameModeBase.h"

#include "Components/CapsuleComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SpotLightComponent.h"


// Sets default values
AMinigameItem::AMinigameItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CurrentMesh = CreateDefaultSubobject<UStaticMeshComponent>("CurrentMesh");
	RootComponent = CurrentMesh;

	InteractCapsule = CreateDefaultSubobject<UCapsuleComponent>("InteractCapsule");
	InteractCapsule->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	LightComponent = CreateDefaultSubobject<USpotLightComponent>("Light");
	LightComponent->SetupAttachment(RootComponent);
}

void AMinigameItem::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (bMoving)
	{
		SplineProgress += DeltaSeconds * Speed;
		
		const FVector Location = SplineRef->GetLocationAtDistanceAlongSpline(SplineProgress * SplineRef->GetSplineLength(), ESplineCoordinateSpace::World);

		// CurrentMesh->AddImpulse(FVector(0,0,0), NAME_None, true);
		
		SetActorLocation(Location, true);
		
		if (SplineProgress >= 1.0f)
		{
			bMoving = false;
			UE_LOG(LogTemp, Display, TEXT("Finished spline progress"));
		}
	}
}

void AMinigameItem::BeginPlay()
{
	Super::BeginPlay();
	
	if (MeshList.IsValidIndex(0))
	{
		CurrentMesh->SetStaticMesh(MeshList[0]);
	}

	if (InteractCapsule)
	{
		InteractCapsule->OnComponentBeginOverlap.AddDynamic(this, &AMinigameItem::OnPickup);
		InteractCapsule->OnComponentEndOverlap.AddDynamic(this, &AMinigameItem::PlayerExit);
	}
}

void AMinigameItem::LaunchAlongSpline(USplineComponent* Spline)
{
	if (Spline)
	{
		SplineRef = Spline;
		bMoving = true;
		SplineProgress = 0.0;
	}
}

void AMinigameItem::OnPickup(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const ADomingoBase* Domingo = Cast<ADomingoBase>(OtherActor))
	{
		bCanInteract = true;

		if (const APlayerController* PC = Cast<APlayerController>(Domingo->GetController()))
		{
			if (const AControlHUD* ControlHUD = Cast<AControlHUD>(PC->GetHUD()))
			{
				if (ControlHUD->PlayerNotificationWidget)
				{
					ControlHUD->PlayerNotificationWidget->UpdateNotification("PRESS X TO INTERACT", true);
				}
			}
		}
	}
}

void AMinigameItem::PlayerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (const ADomingoBase* Domingo = Cast<ADomingoBase>(OtherActor))
	{
		bCanInteract = false;

		if (const APlayerController* PC = Cast<APlayerController>(Domingo->GetController()))
		{
			if (const AControlHUD* ControlHUD = Cast<AControlHUD>(PC->GetHUD()))
			{
				if (ControlHUD->PlayerNotificationWidget)
				{
					ControlHUD->PlayerNotificationWidget->UpdateNotification("", false);
				}
			}
		}
	}
}

void AMinigameItem::PlayerInteract()
{
	if (ADragonKisserST2GameModeBase* GameModeBase =
		Cast<ADragonKisserST2GameModeBase>(GetWorld()->GetAuthGameMode()))
	{
		OnOverlapped.Broadcast();
		GameModeBase->SwapToNewLevel(MiniGameNumber);
		Destroy();
	}
}

void AMinigameItem::SetupMiniGame(const int32 SetupNum)
{
	if (MeshList.IsValidIndex(SetupNum))
	{
		CurrentMesh->SetStaticMesh(MeshList[SetupNum]);
	}

	MiniGameNumber = SetupNum;
}
