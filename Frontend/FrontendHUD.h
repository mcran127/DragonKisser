// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontendUserWidget.h"
#include "SkipCutsceneWidget.h"
#include "GameFramework/HUD.h"
#include "FrontendHUD.generated.h"

UCLASS()
class DRAGONKISSERST2_API AFrontendHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UFrontendUserWidget> Widget;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<UFrontendUserWidget> WidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USkipCutsceneWidget> SkipCutsceneWidget;

	UPROPERTY(EditDefaultsOnly, Category = "HUD")
	TSubclassOf<USkipCutsceneWidget> SkipCutsceneWidgetClass;

	UFUNCTION(BlueprintCallable)
	USkipCutsceneWidget* MakeSkipCutscene();
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetBuilt);
	UPROPERTY(BlueprintAssignable, Category = "HUD")
	FOnWidgetBuilt OnWidgetBuilt;
};
