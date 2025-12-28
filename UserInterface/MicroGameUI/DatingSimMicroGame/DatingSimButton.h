// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "DatingSimButton.generated.h"

/**
 * @class UDatingSimButton
 *
 * Button for the dating sim widget
 */
UCLASS()
class DRAGONKISSERST2_API UDatingSimButton : public UUserWidget
{
	GENERATED_BODY()

	/**
	 * Sets text
	 */
	virtual void NativePreConstruct() override;

	/**
	 * Binds to hovered, unhovered, and pressed
	 */
	virtual void NativeConstruct() override;

	/**
	 * Broadcasts button pressed
	 */
	UFUNCTION()
	void OnButtonPressed();

	/**
	 * On focus, changes color
	 */
	UFUNCTION()
	void OnButtonFocus();

	/**
	 * Calls OnButtonFocus
	 * 
	 * @param InFocusEvent Used in super only
	 */
	virtual void NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent) override;

	/**
	 * On unfocus, reverts color
	 */
	UFUNCTION()
	void OnButtonUnfocus();

	/**
	 * Calls OnButtonUnfocus
	 * 
	 * @param InFocusEvent Used in super only
	 */
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnPressed, bool, FText);
	FOnPressed OnPressed;
	
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextBlock> TextBox;

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UButton> Button;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	bool bIsCorrect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText ResponseText;

};
