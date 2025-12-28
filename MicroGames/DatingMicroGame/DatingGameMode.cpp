// Copyright Brigham Young University. All Rights Reserved.


#include "DatingGameMode.h"

#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/DatingGameHUD.h"

void ADatingGameMode::BeginPlay()
{
	Super::BeginPlay();

	DatingGameHUD = Cast<ADatingGameHUD>(PlayerController->GetHUD());
	PlayerController->SetShowMouseCursor(true);
	
	UMicroGameOverlayWidget* MicroGameOverlayWidget = DatingGameHUD->SetupMicroGameOverlay
	(PlayerController, MinigameText, MinigameTimer);
	
	MicroGameOverlayWidget->OnGameStart.AddUObject(this, &AMicroGameMode::MicroGameStart);
	MicroGameOverlayWidget->OnGameEnd.AddUObject(this, &ThisClass::TimerEnd);
}

void ADatingGameMode::MicroGameStart()
{
	if (DatingGameHUD)
	{
		DatingGameHUD->SetupDatingWidget();
	}
}

void ADatingGameMode::TimerEnd()
{
	if (DatingGameHUD)
	{
		if (DatingGameHUD->MicroGameOverlayWidget)
		{
			DatingGameHUD->DatingSimWidget->DisableButtons();
			DatingGameHUD->MicroGameOverlayWidget->TextUpdate(TimerEndText);

			FTimerHandle TimerHandle;

			TWeakObjectPtr WeakThis(this);
			GetWorldTimerManager().SetTimer(
				TimerHandle,
				[WeakThis]
				{
					if (!WeakThis.IsValid()) {return;}

					ADatingGameMode* DatingGameMode = Cast<ADatingGameMode>(WeakThis.Get());

					DatingGameMode->bWinGame = false;
					DatingGameMode->DatingGameHUD->CloseCurtainProcess();
				},
				2.0f,
				false);
		}
	}
}

void ADatingGameMode::ButtonPressed() const
{
	if (DatingGameHUD)
	{
		if (DatingGameHUD->MicroGameOverlayWidget)
		{
			DatingGameHUD->MicroGameOverlayWidget->bStartTimer = false;
		}
	}
}
