// Copyright Brigham Young University. All Rights Reserved.


#include "MicroGameHUD.h"
#include "../../../MicroGames/MicroGameMode.h"

void AMicroGameHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AMicroGameHUD::OpenCurtainProcess()
{
	if (OpenCurtainClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.TransformScaleMethod = ESpawnActorScaleMethod::MultiplyWithRoot;
				
		OpenCurtainObject = GetWorld()->SpawnActor<ACurtainObject>(
			OpenCurtainClass,
			GetOwningPawn()->GetActorLocation(),
			GetOwningPawn()->GetActorRotation(),
			SpawnParams);
		
		FTimerHandle TimerHandle;

		TWeakObjectPtr WeakThis(this);
		GetWorldTimerManager().SetTimer(
			TimerHandle,
			[WeakThis]
			{
				if (!WeakThis.IsValid()) {return;}
			
				if (const AMicroGameHUD* MicroGameHUD =Cast<AMicroGameHUD>
					(WeakThis.Get()); MicroGameHUD->OpenCurtainObject)
				{
					MicroGameHUD->OpenCurtainObject->Destroy();
				}
			},
			1.0f,
			false);
	}
}

void AMicroGameHUD::CloseCurtainProcess()
{
	if (CloseCurtainClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.TransformScaleMethod = ESpawnActorScaleMethod::SelectDefaultAtRuntime;
				
		CloseCurtainObject = GetWorld()->SpawnActor<ACurtainObject>(
			OpenCurtainClass,
			GetOwningPawn()->GetActorLocation(),
			GetOwningPawn()->GetActorRotation(),
			SpawnParams);

		FTimerHandle TimerHandle;

		TWeakObjectPtr WeakThis(this);
		GetWorldTimerManager().SetTimer(
			TimerHandle,
			[WeakThis]
			{
				if (!WeakThis.IsValid()) {return;}
			
				if (const AMicroGameHUD* MicroGameHUD = Cast<AMicroGameHUD>(WeakThis.Get()))
				{
					AMicroGameMode* MicroGameMode = Cast<AMicroGameMode>(
						MicroGameHUD->GetWorld()->GetAuthGameMode());
					MicroGameMode->MoveToMain(MicroGameMode->bWinGame);
				}
			},
			1.0f,
			false);
	}
}

UMicroGameOverlayWidget* AMicroGameHUD::SetupMicroGameOverlay(APlayerController* PlayerController, const FString& NewText, float NewTimer)
{
	MicroGameOverlayWidget = Cast<UMicroGameOverlayWidget>(CreateWidget(PlayerController, MicroGameOverlayClass));
	MicroGameOverlayWidget->StartingTimerValue = NewTimer;
	MicroGameOverlayWidget->CurrentTimerValue = NewTimer;
	MicroGameOverlayWidget->MinigameDescriptionText = FText::FromString(NewText);

	MicroGameOverlayWidget->AddToViewport();
	return MicroGameOverlayWidget;
}

