// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FrontendGameMode.generated.h"

/**
 * Frontend Game Mode
 */
UCLASS()
class DRAGONKISSERST2_API AFrontendGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AFrontendGameMode();

private:
#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif
};
