// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "MainUIWidget.generated.h"

/**
 * @class UMainUIWidget
 * 
 * Primary widget during the main game. Most widgets should attach to this
 */
UCLASS()
class DRAGONKISSERST2_API UMainUIWidget : public UUserWidget
{
	GENERATED_BODY()

	/**
	 * Binds Rizz subsystem update
	 */
	virtual void NativeConstruct() override;

public:
	/**
	 * Blueprint event, updates rizz
	 * 
	 * @param Ignored ??
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Rizz")
	void RizzUpdated(int Ignored);
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> DomingoPortrait;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	//TArray<TObjectPtr<UTexture2D>> HealthImages;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	TObjectPtr<UProgressBar> StunBar;

	/**
	 * Creates the health objects based on the game subsystem health value
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Health")
	void UpdateHealth();
};
