// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "SkipCutsceneWidget.generated.h"

/**
 * @class USkipCutsceneWidget
 *
 * Widget for skipping the intro cutscene
 */
UCLASS()
class DRAGONKISSERST2_API USkipCutsceneWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTextBlock> TextBox;
};
