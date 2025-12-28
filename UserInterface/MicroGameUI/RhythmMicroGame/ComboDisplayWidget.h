// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ComboDisplayWidget.generated.h"

/**
 * @class UComboDisplayWidget
 *
 * Display showing a rating and a combo amount for the rhythm games
 */
UCLASS()
class DRAGONKISSERST2_API UComboDisplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextBlock> RatingText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ComboText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> FinalText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Combo = 0;

	/**
	 * Makes Rating Text Visible and sets its text
	 * 
	 * @param Text Text to set
	 */
	UFUNCTION(BlueprintCallable)
	void UpdateRating(FString Text) const;

	/**
	 * Makes Final Text visible and sets its text, collapses other components
	 * 
	 * @param Text Text to set
	 */
	UFUNCTION(BlueprintCallable)
	void UpdateFinal(FString Text) const;
};
