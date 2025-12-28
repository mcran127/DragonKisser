// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "DatingBackground.generated.h"

/**
 * @class UDatingBackground
 *
 * Background Widget for the dating sim, likely attached to the dating HUD
 */
UCLASS()
class DRAGONKISSERST2_API UDatingBackground : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget), VisibleAnywhere, Category="Dating")
	TObjectPtr<UImage> DatingBackground;
};
