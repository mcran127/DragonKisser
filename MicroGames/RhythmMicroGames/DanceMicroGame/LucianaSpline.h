// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DanceLuciana.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmSpline.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmTrackComponent.h"
#include "LucianaSpline.generated.h"

/**
 * @class ALucianaSpline
 *
 * Special Spline for Luciana Dance for automatic inputs
 */
UCLASS()
class DRAGONKISSERST2_API ALucianaSpline : public ARhythmSpline
{
	GENERATED_BODY()

public:
	/**
	 * Sets up the child components and set the note class
	 */
	ALucianaSpline();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> RhythmTrackComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<ARhythmTrackComponent> RhythmTrack;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<ADanceLuciana> DanceLuciana;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
	void OnNoteOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	virtual void CueChange(const FName OutputName, const FMetaSoundOutput& Output) override;

};
