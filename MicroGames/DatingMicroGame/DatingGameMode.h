// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameMode.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/DatingGameHUD.h"
#include "DatingGameMode.generated.h"

/**
 * @class ADatingGameMode
 *
 * Dating Game Mode
 */
UCLASS()
class DRAGONKISSERST2_API ADatingGameMode : public AMicroGameMode
{
	GENERATED_BODY()

	/**
	 * Creates the MicroGameOverlay and sets up bindings for start and end
	 */
	virtual void BeginPlay() override;

	/**
	 * Sets up dating widget, overriden from MicroGameMode
	 */
	virtual void MicroGameStart() override;

	/**
	 * Fail condition of MicroGameOverlayWidget. Disables Dating widget buttons, starts a timer, then ends the game
	 */
	void TimerEnd();
	
	UPROPERTY()
	TObjectPtr<ADatingGameHUD> DatingGameHUD;

public:
	
	/**
	 * Stops the timer on the MicroGameOverlayWidget when a button in the Dating Widget is pressed
	 */
	void ButtonPressed() const;

	UPROPERTY(EditAnywhere)
	FText TimerEndText;
};
