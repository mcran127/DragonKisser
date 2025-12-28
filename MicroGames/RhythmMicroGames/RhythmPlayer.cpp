// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmPlayer.h"

#include "EngineUtils.h"
#include "RhythmController.h"
#include "Camera/CameraComponent.h"
#include "DragonKisserST2/MicroGames/MicroGameMode.h"


// Sets default values
ARhythmPlayer::ARhythmPlayer()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
}

// Called when the game starts or when spawned
void ARhythmPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (ARhythmSpline::StaticClass())
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull))
		{
			for (TActorIterator<AActor> It(World, ARhythmSpline::StaticClass()); It; ++It)
			{
				RhythmSpline = Cast<ARhythmSpline>(*It);

				RhythmSpline->OnAudioFinished.AddUObject(this, &ARhythmPlayer::AudioEnd);
				RhythmSpline->OnOverlapOrDestroyed.AddUObject(this, &ARhythmPlayer::UpdateRating);
			}
		}
	}
	if (ADanceDomingo::StaticClass())
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull))
		{
			for (TActorIterator<AActor> It(World, ADanceDomingo::StaticClass()); It; ++It)
			{
				DanceDomingo = Cast<ADanceDomingo>(*It);
			}
		}
	}
	if (AGuitarDomingo::StaticClass())
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull))
		{
			for (TActorIterator<AActor> It(World, AGuitarDomingo::StaticClass()); It; ++It)
			{
				GuitarDomingo = Cast<AGuitarDomingo>(*It);
			}
		}
	}

	if (const ARhythmController* RhythmController = Cast<ARhythmController>(GetController()))
	{
		RhythmHUD = Cast<ARhythmHUD>(RhythmController->GetHUD());
	}

	if (ARhythmController* RhythmController = Cast<ARhythmController>(GetController()))
	{
		RhythmController->OnFirstPress.AddDynamic(this, &ThisClass::OnFirstPress);
		RhythmController->OnFirstRelease.AddDynamic(this, &ThisClass::OnRelease);
		RhythmController->OnSecondPress.AddDynamic(this, &ThisClass::OnSecondPress);
		RhythmController->OnSecondPress.AddDynamic(this, &ThisClass::OnRelease);
		RhythmController->OnThirdPress.AddDynamic(this, &ThisClass::OnThirdPress);
		RhythmController->OnThirdRelease.AddDynamic(this, &ThisClass::OnRelease);
		RhythmController->OnFourthPress.AddDynamic(this, &ThisClass::OnFourthPress);
		RhythmController->OnFourthRelease.AddDynamic(this, &ThisClass::OnRelease);
	}
}

// Called to bind functionality to input
void ARhythmPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARhythmPlayer::UpdateRating(const int32 NoteValue, const int32 Rating) 
{
	switch (Rating)
	{
	case 1:
		RhythmHUD->UpdateCombo("Perfect!", true);
		DomingoDance(NoteValue, true);
		PerfectCount++;
		break;
	case 2:
		RhythmHUD->UpdateCombo("Good", true);
		DomingoDance(NoteValue, true);
		GoodCount++;
		break;
	case 3:
		RhythmHUD->UpdateCombo("Ok", false);
		DomingoDance(NoteValue, false);
		OkCount++;
		break;
	case 4:
		RhythmHUD->UpdateCombo("Miss", false);
		DomingoDance(NoteValue, false);
		break;
	case 0:
	default:
		RhythmHUD->UpdateCombo("Miss", false);
		DomingoDance(NoteValue, false);
		MissCount++;
		break;
	}
}

void ARhythmPlayer::DomingoDance(const int32 NoteValue, const bool bSuccess) const
{
	if (GuitarDomingo)
	{
		GuitarDomingo->DomingoGuitar(bSuccess);
	}
	if (DanceDomingo)
	{
		switch (NoteValue)
		{
		case 0:
			DanceDomingo->DomingoDanceLeft(bSuccess);
			break;
		case 1:
			DanceDomingo->DomingoDanceUp(bSuccess);
			break;
		case 2:
			DanceDomingo->DomingoDanceDown(bSuccess);
			break;
		case 3:
			DanceDomingo->DomingoDanceRight(bSuccess);
			break;
		default:
			DanceDomingo->DomingoDanceRight(bSuccess);
			break;
		}
	}
}

void ARhythmPlayer::AudioEnd()
{
	if (const UWorld* World = GetWorld())
	{
		if (AMicroGameMode* MicroGameMode = Cast<AMicroGameMode>(World->GetAuthGameMode()))
		{
			if (MissCount <= 6)
			{
				MicroGameMode->bWinGame = true;
				EndMessage = "You Win!!!!";
			}
			else
			{
				MicroGameMode->bWinGame = false;
				EndMessage = "You Lose";
			}

			const FString PrepString = TEXT("\nPerfect: ") + FString::FromInt(PerfectCount) +
					 TEXT("\nGood: ") + FString::FromInt(GoodCount) +
					 TEXT("\nOK: ") + FString::FromInt(OkCount) +
					 TEXT("\nMiss: ") + FString::FromInt(MissCount);

			if (RhythmHUD)
			{
				RhythmHUD->UpdateComboDisplayFinal(EndMessage + PrepString);
			}
			
			FTimerHandle TimerHandle;
			TWeakObjectPtr WeakThis(this);
			
			GetWorldTimerManager().SetTimer(
				TimerHandle,
				[WeakThis]
				{
					if (!WeakThis.IsValid()) {return;}

					const ARhythmPlayer* DanceSpline = Cast<ARhythmPlayer>(WeakThis.Get());

					if (const UWorld* World1 = DanceSpline->GetWorld())
					{
						if (AMicroGameMode* GameMode = Cast<AMicroGameMode>(World1->GetAuthGameMode()))
						{
							GameMode->MoveToMain(GameMode->bWinGame);
						}
					}
				},
				3,
				false);
		}
	}
}

void ARhythmPlayer::OnFirstPress()
{
	if (RhythmSpline)
	{
		RhythmSpline->CollisionCheck(0);
	}
}

void ARhythmPlayer::OnSecondPress()
{
	if (RhythmSpline)
	{
		RhythmSpline->CollisionCheck(1);
	}
}

void ARhythmPlayer::OnThirdPress()
{
	if (RhythmSpline)
	{
		RhythmSpline->CollisionCheck(2);
	}
}

void ARhythmPlayer::OnFourthPress()
{
	if (RhythmSpline)
	{
		RhythmSpline->CollisionCheck(3);
	}
}

void ARhythmPlayer::OnRelease()
{
}


