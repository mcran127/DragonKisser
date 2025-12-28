// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ComboDisplayWidget.h"
#include "Blueprint/UserWidget.h"
#include "RhythmWidget.generated.h"

/**
 * @class URhythmWidget
 *
 * Rhythm game overlay. For different positioning between rhythm games
 */
UCLASS()
class DRAGONKISSERST2_API URhythmWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget), EditAnywhere, BlueprintReadWrite, Category="RhythmWidget")
	TObjectPtr<UComboDisplayWidget> ComboDisplayWidget;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "RhythmWidget")
	int32 WidgetsToMake = 0;
};
