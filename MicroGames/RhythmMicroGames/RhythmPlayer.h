// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RhythmSpline.h"
#include "Camera/CameraComponent.h"
#include "DanceMicroGame/DanceDomingo.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/RhythmHUD.h"
#include "GameFramework/Pawn.h"
#include "GuitarMicroGame/GuitarDomingo.h"
#include "RhythmPlayer.generated.h"

/**
 * @class ARhythmPlayer
 *
 * Player Class for both rhythm games
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmPlayer : public APawn
{
	GENERATED_BODY()

public:
	/**
	 * Sets up player camera object
	 */
	ARhythmPlayer();

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, Category = "SplineObject")
	TObjectPtr<ARhythmSpline> RhythmSpline;

	UPROPERTY(VisibleAnywhere, Category = "NoteRating")
	int32 PerfectCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "NoteRating")
	int32 GoodCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "NoteRating")
	int32 OkCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "NoteRating")
	int32 MissCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NoteSpeed")
	FString EndMessage = "";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<ARhythmHUD> RhythmHUD;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Domingo")
	TObjectPtr<ADanceDomingo> DanceDomingo;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Domingo")
	TObjectPtr<AGuitarDomingo> GuitarDomingo;

protected:
	/**
	 * Initializes binds on the spline and controller, and initializes Domingo actor
	 */
	virtual void BeginPlay() override;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/**
	 * Link between spline and HUD to update combo overlay
	 * 
	 * @param NoteValue Value of the note passed in
	 * @param Rating How accurate the player was
	 */
	void UpdateRating(int32 NoteValue, const int32 Rating);

	/**
	 * 
	 * @param NoteValue Value of the note passed in
	 * @param bSuccess Check if player continues their combo
	 */
	void DomingoDance(int32 NoteValue, bool bSuccess) const;

	/**
	 * When the audio is done, print final message and end the microgame
	 */
	void AudioEnd();

	/**
	 * On either left shoulder or left pressed, check collision
	 */
	UFUNCTION()
	void OnFirstPress();

	/**
	 * On either left trigger or up pressed, check collision
	 */
	UFUNCTION()
	void OnSecondPress();

	/**
	 * On either right shoulder or down pressed, check collision
	 */
	UFUNCTION()
	void OnThirdPress();

	/**
	 * On either right trigger or right pressed, check collision
	 */
	UFUNCTION()
	void OnFourthPress();

	/**
	 * On button release, change mesh back (currently unused)
	 */
	UFUNCTION()
	void OnRelease();
};
