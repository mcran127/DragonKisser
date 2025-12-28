// Copyright Brigham Young University. All Rights Reserved.


#include "ClinkTrigger.h"

#include "ClinkCharacter.h"
#include "ClinkGameMode.h"


// Sets default values
AClinkTrigger::AClinkTrigger()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AClinkTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void AClinkTrigger::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const AClinkCharacter* ClinkCharacter = Cast<AClinkCharacter>(OtherActor))
	{
		if (GetWorld())
		{
			if (AClinkGameMode* ClinkGameMode = Cast<AClinkGameMode>(GetWorld()->GetAuthGameMode()))
			{
				if (ClinkCharacter->GetVelocity().Length() > TooFastSpeed)
				{
					ClinkGameMode->bWinGame = false;
					ClinkGameMode->GameEndTextLose = "Slow down! You're making a mess";
					ClinkGameMode->DisplayEndText();
				}
				else
				{
					ClinkGameMode->bWinGame = true;
				}
			}
		}
	}
}

void AClinkTrigger::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(AClinkCharacter::StaticClass()))
	{
		if (GetWorld())
		{
			if (AClinkGameMode* ClinkGameMode = Cast<AClinkGameMode>(GetWorld()->GetAuthGameMode()))
			{
				ClinkGameMode->bWinGame = false;
			}
		}
	}
}


