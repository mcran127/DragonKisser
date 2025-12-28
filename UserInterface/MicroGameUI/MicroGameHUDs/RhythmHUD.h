// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/MicroGameHUD.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/RhythmMicroGame/RhythmWidget.h"
#include "RhythmHUD.generated.h"

/**
 * @class ARhythmHUD
 *
 * HUD for the dance and guitar microgames
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmHUD : public AMicroGameHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<URhythmWidget> RhythmWidgetClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<URhythmWidget> RhythmWidget;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UComboDisplayWidget> ComboDisplayWidget;

	/**
	 * Creates rhythm and rating widgets and sets combo display widget
	 */
	void SetupRhythmWidget();

	/**
	 * Calls ComboDisplayWidget's Update Final
	 * 
	 * @param ToUpdate Text to set
	 */
	void UpdateComboDisplayFinal(const FString& ToUpdate) const;

	/**
	 * Calls ComboDisplayWidget's Update Final
	 * 
	 * @param ComboRating Combo Rating String
	 * @param IncrementCombo Bool to increment combo
	 */
	void UpdateCombo(const FString& ComboRating, const bool IncrementCombo) const;
};
