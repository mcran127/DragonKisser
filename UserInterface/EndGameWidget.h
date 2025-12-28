// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "EndGameWidget.generated.h"

/**
 * @class UEndGameWidget
 *
 * Win/Lose Screen Widget
 */
UCLASS(Abstract)
class DRAGONKISSERST2_API UEndGameWidget final : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/**
	 * Blueprint event to set image based on end game images
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetImage();
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UImage> EndGameImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinLose")
	int32 WinLoseVal = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EndGameImages")
	TArray<TObjectPtr<UTexture2D>> EndGameImages;
};
