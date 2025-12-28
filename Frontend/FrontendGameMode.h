// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FrontendGameMode.generated.h"

/**
 * @class AFrontendGameMode
 *
 * Game mode for the frontend
 */
UCLASS()
class DRAGONKISSERST2_API AFrontendGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	/**
	 * Sets up game mode values
	 */
	AFrontendGameMode();

private:
#if WITH_EDITOR
	/**
	 * Only checks in editor, checks if game mode context is valid
	 * 
	 * @param Context Current context for frontend
	 * @return Valid or not data
	 */
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif
};
