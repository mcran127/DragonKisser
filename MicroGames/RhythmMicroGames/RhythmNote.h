// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "GameFramework/Actor.h"
#include "RhythmNote.generated.h"

/**
 * @class ARhythmNote
 *
 * Base Note class for rhythm microgames
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmNote : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Creates Plane Object
	 */
	ARhythmNote();

	/**
	 * @brief Move note on tick.
	 * If "bMoving" is set, on tick, move the note in the direction of the "Lane".
	 * @param DeltaSeconds Change in seconds from last frame
	 */
	virtual void Tick(float DeltaSeconds) override;

	/**
	 * Sets parent Lane and NoteSpeed, then begins movement.
	 * @param NewLane The parent Lane. Used to determine note direction.
	 * @param NoteSpeed The notes speed in seconds.
	 */
	UFUNCTION(BlueprintCallable)
	void StartMovement(USplineComponent* NewLane, float NoteSpeed);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TObjectPtr<UStaticMeshComponent> PlaneMesh;
	
	float DistanceAlongSpline = 0.0;

	bool bMoving = false;
	float NoteRate = 0.0;

	UPROPERTY()
	TObjectPtr<USplineComponent> Lane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NoteValue = 0;

};
