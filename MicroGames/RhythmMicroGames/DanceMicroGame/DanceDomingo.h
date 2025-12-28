// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmActor.h"
#include "GameFramework/Actor.h"
#include "DanceDomingo.generated.h"

/**
* @class ADanceDomingo
*
* Domingo Dance Actor in the Dance Microgame
*/
UCLASS()
class DRAGONKISSERST2_API ADanceDomingo : public ARhythmActor
{
	GENERATED_BODY()

public:
	ADanceDomingo();
	
	/**
	 * Checks if the dance succeeds. If so, adjust material to the dance up material, then revert to idle
	 * 
	 * @param Success Did the dance succeed or not?
	 */
	UFUNCTION()
	void DomingoDanceUp(bool Success);

	/**
	 * Checks if the dance succeeds. If so, adjust material to the dance left material, then revert to idle
	 * 
	 * @param Success Did the dance succeed or not?
	 */
	UFUNCTION()
	void DomingoDanceLeft(bool Success);

	/**
	 * Checks if the dance succeeds. If so, adjust material to the dance right material, then revert to idle
	 * 
	 * @param Success Did the dance succeed or not?
	 */
	UFUNCTION()
	void DomingoDanceRight(bool Success);

	/**
	 * Checks if the dance succeeds. If so, adjust material to the dance down material, then revert to idle
	 * 
	 * @param Success Did the dance succeed or not?
	 */
	UFUNCTION()
	void DomingoDanceDown(bool Success);

protected:
	/**
	 * Initialize to material index 5 on AllMaterials
	 */
	virtual void BeginPlay() override;
	
};
