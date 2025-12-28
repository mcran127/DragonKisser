// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameTrigger.h"
#include "ClinkTrigger.generated.h"

/**
 * @class AClinkTrigger
 *
 * Child of microgame trigger, trigger focusing on is currently overlapped within clink minigame
 */
UCLASS()
class DRAGONKISSERST2_API AClinkTrigger : public AMicroGameTrigger
{
	GENERATED_BODY()

public:
	/**
	 * Sets tick to false
	 */
	AClinkTrigger();

	UPROPERTY(EditDefaultsOnly, Category = "Speed")
	float TooFastSpeed = 1500;

protected:
	/**
	 * Calls super
	 */
	virtual void BeginPlay() override;

	/**
	 * Checks if player entered overlap too fast. If not, sets win to true
	 * 
	 * @param OverlappedComp N/A
	 * @param OtherActor Player Actor entering overlap
	 * @param OtherComp N/A
	 * @param OtherBodyIndex N/A
	 * @param bFromSweep N/A
	 * @param SweepResult N/A
	 */
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	/**
	 * Disables win when player exits overlap
	 * 
	 * @param OverlappedComp N/A
	 * @param OtherActor Player Actor exiting overlap
	 * @param OtherComp N/A
	 * @param OtherBodyIndex N/A
	 */
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;
};
