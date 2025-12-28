// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontendUserWidget.h"
#include "SkipCutsceneWidget.h"
#include "GameFramework/HUD.h"
#include "FrontendHUD.generated.h"

/**
 * @class AFrontendHUD
 *
 * Frontend HUD class. Contains the frontend and skip cutscene widgets
 */
UCLASS()
class DRAGONKISSERST2_API AFrontendHUD : public AHUD
{
	GENERATED_BODY()

protected:
	/**
	 * Generates a frontend widget based on the blueprint provided class. Broadcasts to the level blueprint
	 */
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UFrontendUserWidget> Widget;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UFrontendUserWidget> WidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USkipCutsceneWidget> SkipCutsceneWidget;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<USkipCutsceneWidget> SkipCutsceneWidgetClass;

	/**
	 * Creates a skip cutscene widget from the blueprint provided class
	 * 
	 * @return Reference to the Skip Cutscene Widget
	 */
	UFUNCTION(BlueprintCallable)
	USkipCutsceneWidget* MakeSkipCutscene();
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetBuilt);
	UPROPERTY(BlueprintAssignable, Category = "HUD")
	FOnWidgetBuilt OnWidgetBuilt;
};
