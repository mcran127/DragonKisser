// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SplineComponent.h"
#include "RhythmTrackComponent.generated.h"

/**
 * @class ARhythmTrackComponent
 *
 * Rhythm MicroGame track mesh
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmTrackComponent : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Sets up components
	 */
	ARhythmTrackComponent();

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnDestroyOverlap, int32, int32)
	FOnDestroyOverlap OnDestroyOverlap;

	/**
	 * Sets up on destroy overlap
	 */
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UBoxComponent> Spawner;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UBoxComponent> Destroyer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UBoxComponent> SplineTrack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<USplineComponent> NoteLane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> Plane;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> BackgroundTrack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> RatingPlane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TArray<TObjectPtr<UMaterial>> RatingImages;

	/**
	 * Updates rating material. Currently using basic materials but will replace with images of Perfect, Great, etc.
	 * 
	 * @param Rating Rating of the player overlap
	 */
	void UpdateRatingMaterial(int32 Rating);

private:
	/**
	 * Destroys overlapping note after broadcasting on destroy to spline
	 * 
	 * @param OverlappedComp N/A
	 * @param OtherActor Note Overlapping with the Destroyer
	 * @param OtherComp N/A
	 * @param OtherBodyIndex N/A
	 * @param bFromSweep N/A
	 * @param SweepResult N/A
	 */
	UFUNCTION()
	void OnDestroyerOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	
};
