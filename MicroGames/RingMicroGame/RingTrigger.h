// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameTrigger.h"
#include "RingTrigger.generated.h"

UCLASS()
class DRAGONKISSERST2_API ARingTrigger : public AMicroGameTrigger
{
	GENERATED_BODY()

public:
	
	ARingTrigger();

	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	TObjectPtr<UBoxComponent> BlockBox1;

	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	TObjectPtr<UBoxComponent> BlockBox2;

	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	TObjectPtr<UBoxComponent> RotationBox;

	UPROPERTY(EditDefaultsOnly, Category="Rotate")
	FRotator ToRotate;

	UPROPERTY(EditDefaultsOnly, Category="Win")
	bool bPlayerWin;

protected:
	/**
	 * Sets up rotation box on enter and leave
	 */
	virtual void BeginPlay() override;

	/**
	 * 
	 * @param OverlappedComp 
	 * @param OtherActor 
	 * @param OtherComp 
	 * @param OtherBodyIndex 
	 * @param bFromSweep 
	 * @param SweepResult 
	 */
	UFUNCTION(BlueprintCallable)
	virtual void OnRotationBoxBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	/**
	 * Calls on end behavior. to be overriden by implementations
	 * 
	 * @param OverlappedComp N/A
	 * @param OtherActor Note Overlapping with the Destroyer
	 * @param OtherComp N/A
	 * @param OtherBodyIndex N/A
	 */
	UFUNCTION(BlueprintCallable)
	virtual void OnRotationBoxEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
	
	/**
	 * Calls End Game when entering overlap
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

};
