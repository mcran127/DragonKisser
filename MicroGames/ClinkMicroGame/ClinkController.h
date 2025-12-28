// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameController.h"
#include "ClinkController.generated.h"

/**
 * @class AClinkController
 *
 * Controller for the ClinkMinigame
 */
UCLASS()
class DRAGONKISSERST2_API AClinkController : public AMicroGameController
{
	GENERATED_BODY()

	/**
	 * Calls super and then binds Clink microgame controls
	 */
	virtual void SetupInputComponent() override;

	/**
	 * Broadcasts value to pawn
	 * 
	 * @param Value 2D vector controller input
	 */
	void MoveInputTriggered(const FInputActionValue& Value);

protected:

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Move_Action;
};
