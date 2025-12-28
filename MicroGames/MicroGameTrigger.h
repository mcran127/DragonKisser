// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MicroGameTrigger.generated.h"

/**
 * @class AMicroGameTrigger
 *
 * Trigger overlap box for ring and clink microgames
 */
UCLASS()
class DRAGONKISSERST2_API AMicroGameTrigger : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Creates root box component
	 */
	AMicroGameTrigger();

	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	TObjectPtr<UBoxComponent> TriggerBox;

protected:
	/**
	 * Binds on begin and end overlap
	 */
	virtual void BeginPlay() override;

	/**
	 * Sets variables, to be overriden by child
	 * 
	 * @param OverlappedComp N/A
	 * @param OtherActor Player Actor entering overlap
	 * @param OtherComp N/A
	 * @param OtherBodyIndex N/A
	 * @param bFromSweep N/A
	 * @param SweepResult N/A
	 */
	UFUNCTION(BlueprintCallable)
	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	/**
	 * Resets variables, to be overriden by child
	 * 
	 * @param OverlappedComp N/A
	 * @param OtherActor Player Actor leaving overlap
	 * @param OtherComp N/A
	 * @param OtherBodyIndex N/A
	 */
	UFUNCTION(BlueprintCallable)
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};
