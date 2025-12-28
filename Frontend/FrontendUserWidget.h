// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FrontendUserWidget.generated.h"

/**
 * @class UFrontendUserWidget
 *
 * Frontend widget
 */
UCLASS()
class DRAGONKISSERST2_API UFrontendUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * Calls super
	 */
	virtual void NativeConstruct() override;
};
