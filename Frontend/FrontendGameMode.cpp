// Copyright Brigham Young University. All Rights Reserved.


#include "FrontendGameMode.h"

#include "FrontendGameState.h"
#include "FrontendHUD.h"
#include "FrontendPlayerState.h"
#include "Misc/DataValidation.h"

AFrontendGameMode::AFrontendGameMode()
{
	DefaultPawnClass = nullptr;
	GameSessionClass = nullptr;
	ReplaySpectatorPlayerControllerClass = nullptr;
	ServerStatReplicatorClass = nullptr;
	SpectatorClass = nullptr;
	PlayerStateClass = AFrontendPlayerState::StaticClass();
	HUDClass = AFrontendHUD::StaticClass();
	GameStateClass = AFrontendGameState::StaticClass();
}

#if WITH_EDITOR
EDataValidationResult AFrontendGameMode::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = Super::IsDataValid(Context);

	if (PlayerStateClass != AFrontendPlayerState::StaticClass())
	{
		Context.AddError(INVTEXT("PlayerStateClass must be AFrontendPlayerState"));
		Result = EDataValidationResult::Invalid;
	}

	if (GameStateClass != AFrontendGameState::StaticClass())
	{
		Context.AddError(INVTEXT("GameStateClass must be AFrontendState"));
		Result = EDataValidationResult::Invalid;
	}

	if (HUDClass)
	{
		if (!HUDClass->IsChildOf<AFrontendHUD>())
		{
			Context.AddError(INVTEXT("HUDClass must be a child of AFrontendHUD"));
			Result = EDataValidationResult::Invalid;
		}

		if (HUDClass->HasAnyClassFlags(CLASS_Abstract))
		{
			Context.AddError(INVTEXT("HUDClass must not be abstract"));
			Result = EDataValidationResult::Invalid;
		}
	}
	else
	{
		Context.AddError(INVTEXT("HUDClass must be set"));
		Result = EDataValidationResult::Invalid;
	}

	return Result;
}
#endif