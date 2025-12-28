// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MetasoundGeneratorHandle.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmSpline.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmTrackComponent.h"
#include "GameFramework/Actor.h"
#include "GuitarSpline.generated.h"

class AGuitarNote;
class UMetaSoundSource;

/**
 * @class AGuitarSpline
 *
 * Spline class for Guitar Microgame, inherited from ARhythmSpline
 */
UCLASS(Blueprintable)
class DRAGONKISSERST2_API AGuitarSpline : public ARhythmSpline
{
	GENERATED_BODY()

public:
	/**
	 * Sets up overlap and track components
	 */
	AGuitarSpline();

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> TrackLeftComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> TrackUpComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> TrackDownComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> TrackRightComponent;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARhythmTrackComponent> TrackLeft;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARhythmTrackComponent> TrackUp;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARhythmTrackComponent> TrackDown;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARhythmTrackComponent> TrackRight;

	/**
	 * Spawn a note based on the current label
	 * 
	 * @param OutputName Unused
	 * @param Output Unused
	 */
	virtual void CueChange(const FName OutputName, const FMetaSoundOutput& Output) override;

protected:
	/**
	 * Sets up on overlap or destroy dispatcher
	 */
	virtual void BeginPlay() override;

	/**
	 * Updates the rating of the rating box
	 * 
	 * @param Location Which track to update
	 * @param Rating Rating of the collision check
	 */
	void UpdateRating(const int32 Location, const int32 Rating) const;

private:
	/**
	 * Spawn a Note along a give spline
	 * 
	 * @param Lane spline note will follow
	 * @param SpawnLocation Location where note spawns
	 * @param SpawnRotation rotation of Note
	 * @param NoteValue value of note
	 */
	UFUNCTION(BlueprintCallable, Category = "Guitar")
	void SpawnNote(USplineComponent* Lane, const FVector SpawnLocation, const FRotator SpawnRotation, const int32 NoteValue) const;

	/**
	 * Activates a rhythm effect when a note is hit
	 * 
	 * @param Location Location for the niagara effect to be put
	 */
	virtual void ActivateNiagaraSystem(int32 Location) override;

};
