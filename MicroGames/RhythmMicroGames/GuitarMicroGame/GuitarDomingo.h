// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmActor.h"
#include "GameFramework/Actor.h"
#include "GuitarDomingo.generated.h"

/**
 * @class AGuitarDomingo
 *
 * Domingo actor for guitar rhythm game
 */
UCLASS()
class DRAGONKISSERST2_API AGuitarDomingo : public ARhythmActor
{
	GENERATED_BODY()

public:
	AGuitarDomingo();

	/**
	 * Checks if the dance succeeds. If so, adjust material to the playing guitar material, then revert to idle
	 * 
	 * @param Success Did the dance succeed or not?
	 */
	UFUNCTION()
	void DomingoGuitar(bool Success);

protected:
	/**
	 * Initialize to material index 0 on AllMaterials
	 */
	virtual void BeginPlay() override;

};
