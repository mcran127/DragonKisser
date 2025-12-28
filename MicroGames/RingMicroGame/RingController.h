// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameController.h"
#include "RingController.generated.h"

/**
 * @class ARingController
 *
 * Controller for the Ring Minigame
 */
UCLASS()
class DRAGONKISSERST2_API ARingController : public AMicroGameController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	void MoveRing(const FInputActionValue& Value);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Input|Ring")
	TObjectPtr<UInputAction> Move_Action;

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveRing, const FInputActionValue&, Value);
	UPROPERTY()
	FOnMoveRing OnMoveRing;
};
