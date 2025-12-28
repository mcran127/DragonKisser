// Copyright Brigham Young University. All Rights Reserved.


#include "RingGameMode.h"

void ARingGameMode::BeginPlay()
{
	Super::BeginPlay();

	MicroGameHUD = Cast<AMicroGameHUD>(PlayerController->GetHUD());

	PlayerController->SetIgnoreMoveInput(true);

	UMicroGameOverlayWidget* MicroGameOverlayWidget = MicroGameHUD->SetupMicroGameOverlay
	(PlayerController, MinigameText, MinigameTimer);
	
	MicroGameOverlayWidget->OnGameStart.AddUObject(this, &AMicroGameMode::MicroGameStart);
	MicroGameOverlayWidget->OnGameEnd.AddUObject(this, &ThisClass::TimerEnd);
}

void ARingGameMode::TimerEnd()
{
	if (MicroGameHUD)
	{
		if (MicroGameHUD->MicroGameOverlayWidget)
		{
			PlayerController->SetIgnoreMoveInput(true);
			
			MicroGameHUD->MicroGameOverlayWidget->TextUpdate(TimerEndText);

			EndRingGame(false);
		}
	}
}

void ARingGameMode::MicroGameStart()
{
	Super::MicroGameStart();

	PlayerController->SetIgnoreMoveInput(false);
}

void ARingGameMode::DisplayEndText(bool bWon)
{
	PlayerController->SetIgnoreMoveInput(true);
	
	if (MicroGameHUD)
	{
		if (MicroGameHUD->MicroGameOverlayWidget)
		{
			MicroGameHUD->MicroGameOverlayWidget->bStartTimer = false;
			
			bWon ?
				MicroGameHUD->MicroGameOverlayWidget->TextUpdate(FText::FromString(GameEndTextWin)) :
				MicroGameHUD->MicroGameOverlayWidget->TextUpdate(FText::FromString(GameEndTextLose));

			EndRingGame(bWon);
		}
	}
}

void ARingGameMode::EndRingGame(bool bWon)
{
	FTimerHandle TimerHandle;

	TWeakObjectPtr WeakThis(this);
	GetWorldTimerManager().SetTimer(
		TimerHandle,
		[WeakThis, bWon]
		{
			if (!WeakThis.IsValid()) {return;}

			ARingGameMode* RingGameMode = Cast<ARingGameMode>(WeakThis.Get());

			RingGameMode->bWinGame = bWon;
			RingGameMode->MicroGameHUD->CloseCurtainProcess();
		},
		2.0f,
		false);
}
