// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MetasoundGeneratorHandle.h"
#include "RhythmOverlap.h"
#include "RhythmSpline.generated.h"

UCLASS(Abstract, Blueprintable)
/**
 * @class ARhythmSpline
 *
 * Base Rhythm Spline Object for Rhythm Rhythm Game
 */
class DRAGONKISSERST2_API ARhythmSpline : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Initialize SecondsPerBeat, NoteSpeed, and DelayTime
	 */
	ARhythmSpline();

	DECLARE_MULTICAST_DELEGATE(FOnAudioFinsihed)
	FOnAudioFinsihed OnAudioFinished;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnDestroyed, int32, int32)
	FOnDestroyed OnOverlapOrDestroyed;

	//Mesh
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	TObjectPtr<UChildActorComponent> RhythmOverlapComponent;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ARhythmOverlap> RhythmOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RhythmSpline")
	float BeatsPerMinute = 120.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RhythmSpline")
	float BeatsToWait = 4.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RhythmSpline")
	float NoteSpeed = 1.6667;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RhythmSpline")
	int CurrentTrack = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RhythmSpline")
	FString EndMessage = "";

	/**
	 * Call Audio Finished broadcast
	 */
	UFUNCTION(BlueprintCallable)
	void AudioFinishedEvent();

	/**
	 * Blueprint event, sets up meta sound system and spawns notes for the duration of the song
	 */
	UFUNCTION(BlueprintCallable, Category = "MetaSound")
	void SetupSound();

	/**
	 * Calls the Overlap component's collision check
	 * 
	 * @param Value Input for the collision check
	 */
	UFUNCTION()
	void CollisionCheck(int32 Value) const;

	/**
	 * Unused, meant to revert plane mesh if we decide to have it change
	 */
	UFUNCTION()
	void OnRelease();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * Broadcast overlap or destroy
	 * 
	 * @param NoteValue Value of the note (up down left right)
	 * @param Rating How successful the collision check
	 */
	void OverlapOrDestroyed(int32 NoteValue, int32 Rating);

	
	FOnMetasoundOutputValueChanged OnLabelChange;
	/**
	 * Sets the current label based on the output
	 * 
	 * @param OutputName Unused
	 * @param Output String to set to current label
	 */
	UFUNCTION(BlueprintCallable)
	virtual void LabelChange(const FName OutputName, const FMetaSoundOutput& Output);

	FOnMetasoundOutputValueChanged OnCueChange;
	/**
	 * To be overriden by children
	 * 
	 * @param OutputName Unused
	 * @param Output Unused
	 */
	UFUNCTION(BlueprintCallable)
	virtual void CueChange(const FName OutputName, const FMetaSoundOutput& Output);

	bool bCollisionCheckZ = false;

	/**
	 * Plays niagara effect, to be overriden by children
	 * 
	 * @param Location Location for niagara effect
	 */
	virtual void ActivateNiagaraSystem(int32 Location);

	UPROPERTY(EditAnywhere, Category = "Firing")
	UNiagaraSystem* RhythmBurst;

	UPROPERTY(BlueprintReadWrite, Category = "Guitar", meta = (AllowPrivateAccess = "true"))
	FString CurrentLabel;

	UPROPERTY(EditAnywhere, Category = "MetaSound", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMetaSoundSource> MetaSoundTrack;

	UPROPERTY(VisibleAnywhere, Category="MetaSound")
	TObjectPtr<UAudioComponent> AudioComponent;

	/// Class for the Note that should be spawned
	UPROPERTY(EditAnywhere, Category = "Guitar", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ARhythmNote> NoteClass;
};
