// Copyright Brigham Young University. All Rights Reserved.


#include "ClinkGameMode.h"

void AClinkGameMode::BeginPlay()
{
	Super::BeginPlay();

	MicroGameHUD = Cast<AMicroGameHUD>(PlayerController->GetHUD());

	PlayerController->SetIgnoreMoveInput(true);

	UMicroGameOverlayWidget* MicroGameOverlayWidget = MicroGameHUD->SetupMicroGameOverlay
	(PlayerController, MinigameText, MinigameTimer);
	
	MicroGameOverlayWidget->OnGameStart.AddUObject(this, &AMicroGameMode::MicroGameStart);
	MicroGameOverlayWidget->OnGameEnd.AddUObject(this, &ThisClass::DisplayEndText);
}

void AClinkGameMode::MicroGameStart()
{
	PlayerController->SetIgnoreMoveInput(false);

	if (GetWorld() && LucianaClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		const FVector SpawnLocation(
			FMath::RandRange(500.f, 1500.f),
			0.f,
			FMath::RandRange(-1000.f, 1000.f)
		);

		const FRotator SpawnRotation = FRotator::ZeroRotator;

		ALucianaClink* SpawnedActor = GetWorld()->SpawnActor<ALucianaClink>(
			LucianaClass,
			SpawnLocation,
			SpawnRotation,
			SpawnParams
		);

		if (SpawnedActor)
		{
			SpawnedActor->SetActorScale3D(FVector(6.0f));
		}
	}
}

void AClinkGameMode::DisplayEndText()
{
	PlayerController->SetIgnoreMoveInput(true);
	
	if (MicroGameHUD)
	{
		if (MicroGameHUD->MicroGameOverlayWidget)
		{
			MicroGameHUD->MicroGameOverlayWidget->bStartTimer = false;
			
			bWinGame ?
				MicroGameHUD->MicroGameOverlayWidget->TextUpdate(FText::FromString(GameEndTextWin)) :
				MicroGameHUD->MicroGameOverlayWidget->TextUpdate(FText::FromString(GameEndTextLose));

			EndClinkGame(bWinGame);
		}
	}
}

void AClinkGameMode::EndClinkGame(bool bWon)
{
	FTimerHandle TimerHandle;

	TWeakObjectPtr WeakThis(this);
	GetWorldTimerManager().SetTimer(
		TimerHandle,
		[WeakThis, bWon]
		{
			if (!WeakThis.IsValid()) {return;}

			AClinkGameMode* ClinkGameMode = Cast<AClinkGameMode>(WeakThis.Get());

			ClinkGameMode->bWinGame = bWon;
			ClinkGameMode->MicroGameHUD->CloseCurtainProcess();
		},
		2.0f,
		false);
}
