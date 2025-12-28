// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmSpline.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmTrackComponent.h"
#include "DanceSpline.generated.h"

/**
 * @class ADanceSpline
 *
 * Spline class for Dance Microgame, inherited from ARhythmSpline
 */
UCLASS(Blueprintable)
class DRAGONKISSERST2_API ADanceSpline : public ARhythmSpline
{
	GENERATED_BODY()

public:
	/**
	 * Sets up the child components and set the note class
	 */
	ADanceSpline();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> RhythmTrackComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<ARhythmTrackComponent> RhythmTrack;

protected:
	/**
	 * Sets up on overlap or destroy dispatcher
	 */
	virtual void BeginPlay() override;

	/**
	 * Updates the rating of the rating box
	 * 
	 * @param Location Unused, using pre-existing broadcast
	 * @param Rating Rating of the collision check
	 */
	void UpdateRating(int32 Location, int32 Rating) const;

	/**
	 * Activates a rhythm effect when a note is hit
	 * 
	 * @param Location Location for the niagara effect to be put
	 */
	virtual void ActivateNiagaraSystem(int32 Location) override;

	/**
	 * Spawns note based on note value
	 * 
	 * @param OutputName Unused
	 * @param Output Unused
	 */
	virtual void CueChange(const FName OutputName, const FMetaSoundOutput& Output) override;
	
};