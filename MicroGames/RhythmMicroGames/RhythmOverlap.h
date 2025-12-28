// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "Components/BoxComponent.h"
#include "DanceMicroGame/DanceNote.h"
#include "GameFramework/Actor.h"
#include "RhythmOverlap.generated.h"

/**
 * @class ARhythmOverlap
 *
 * Overlap Object Component for the rhythm game tracks
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmOverlap : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnOverlap, int32, int32)
	FOnOverlap OnOverlap;

	DECLARE_MULTICAST_DELEGATE_OneParam(FOnNiagara, int32)
	FOnNiagara OnNiagara;

	/**
	 * Initialize collision box
	 */
	ARhythmOverlap();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UBoxComponent> OverlapBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoteRating")
	float PerfectCollisionThreshold = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoteRating")
	float GoodCollisionThreshold = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoteRating")
	float OkCollisionThreshold = 15.0f;

	/**
	 * Checks if a note is overlapping the collision
	 * box and how close to the center it is
	 * 
	 * @param Key This key helps check what note is passing through the collision box
	 * @param bCollisionCheckZ This checks if the overlap should only check the Z distance difference
	 */
	UFUNCTION()
	void CollisionCheck(int32 Key, bool bCollisionCheckZ);

protected:
	virtual void BeginPlay() override;

};
