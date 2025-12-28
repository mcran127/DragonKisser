// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerPromptWidget.generated.h"

/**
 * @class UPlayerPromptWidget
 *
 * Prompts the player to do things like dodge or parry
 */
UCLASS()
class DRAGONKISSERST2_API UPlayerPromptWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * Shows or hides notification for the player
	 * 
	 * @param NewText Text to set
	 * @param bVisible Show or hide notification
	 */
	UFUNCTION(BlueprintNativeEvent, Category="Notification")
	void UpdateNotification(const FString& NewText, bool bVisible);
};
