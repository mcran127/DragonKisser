// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "KissWidget.generated.h"

class UButton;
class UEndGameWidget;
/**
 * @class UKissWidget
 *
 * Widget for Kiss Microgame
 */
UCLASS()
class DRAGONKISSERST2_API UKissWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true", Category = "Slider"))
	TObjectPtr<UImage> DragonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true", Category = "Slider"))
	TObjectPtr<UImage> DomingoImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true", Category = "Slider"))
	TObjectPtr<UButton> KissButton;

public:
	UPROPERTY(meta = (BindWidgetAnim), Transient, BlueprintReadWrite)
	TObjectPtr<UWidgetAnimation> SliderAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> FrontendLevelReference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanPress = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UEndGameWidget> FinalWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UEndGameWidget> FinalWidget;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USoundBase> WinJingle;

	void PlaySliderAnimation();

	UFUNCTION(BlueprintCallable, Category = "Slider")
	void OnButtonPushed();
};
