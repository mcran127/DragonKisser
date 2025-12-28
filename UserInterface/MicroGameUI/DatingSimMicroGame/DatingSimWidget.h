// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DatingSimButton.h"
#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "DragonKisserST2/GameInstance/GameInstanceBase.h"
#include "DragonKisserST2/MicroGames/DatingMicroGame/DataAssets/QuestionAnswerDataAsset.h"
#include "DatingSimWidget.generated.h"

/**
 * @class UDatingSimWidget
 *
 * Dating Simulator Widget
 */
UCLASS()
class DRAGONKISSERST2_API UDatingSimWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UGameInstanceBase> DragonKisserGameInstance;

	/**
	 * Checks if a threshold value was reached
	 * 
	 * @param Threshold Threshold value reached
	 * @return Was the value reached
	 */
	bool CheckDatingThreshold(int32 Threshold);

	/**
	 * Sets the response, disables buttons and calls a dispatcher on if it was correct, then closes curtains
	 * 
	 * @param bIsCorrect Was the answer correct
	 * @param Response Response text to set
	 */
	void OnButtonPressed(bool bIsCorrect, FText Response);

	bool bSuccess = false;


public:
	DECLARE_MULTICAST_DELEGATE(FOnPressedButton);
	FOnPressedButton OnPressedButton;
	
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextBlock> DragonTextBox;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UHorizontalBox> AnswerBox;

	/**
	 * Chooses questions based on thresholds
	 */
	virtual void NativeConstruct() override;

	/**
	 * Takes all buttons and disables them
	 */
	UFUNCTION()
	void DisableButtons();

	/**
	 * Shuffles possible questions and creates dating sim buttons
	 * 
	 * @param QuestionList List of questions and answers to use for setup
	 */
	UFUNCTION()
	void SetupQuestions(UQuestionAnswerDataAsset* QuestionList);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buttons")
	TArray<TObjectPtr<UDatingSimButton>> AllButtons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Question")
	TArray<TObjectPtr<UQuestionAnswerDataAsset>> QuestionAnswerSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Question")
	TSubclassOf<UDatingSimButton> ButtonClass;
};
