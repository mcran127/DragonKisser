// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "MicroGameOverlayWidget.generated.h"

/**
 * @class UMicroGameOverlayWidget
 *
 * Widget for non rhythm microgames
 */
UCLASS()
class DRAGONKISSERST2_API UMicroGameOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE(FOnGameEnd);
	FOnGameEnd OnGameEnd;

	DECLARE_MULTICAST_DELEGATE(FOnGameStart);
	FOnGameStart OnGameStart;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextBlock> WinLoseObjective;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UProgressBar> Timer;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBorder> TextBorder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText MinigameDescriptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	float StartingTimerValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	float CurrentTimerValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	bool bStartTimer = false;
	
	virtual void NativePreConstruct() override;

	/**
	 * Creates help text and broadcasts start microgame to the game mode after a timer
	 */
	virtual void NativeConstruct() override;

	/**
	 * Handles timer logic, broadcasts on end when finished
	 * 
	 * @param MyGeometry Unused
	 * @param InDeltaTime DeltaTime
	 */
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	/**
	 * Updates WinLoseObjective text and makes it visible
	 * 
	 * @param NewText Text to show
	 */
	UFUNCTION(BlueprintCallable, Category = "Text")
	void TextUpdate(FText NewText);
};
