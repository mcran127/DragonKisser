// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "MicroGameInputComponent.generated.h"

/**
 * @class UMicroGameInputComponent
 *
 * Input component for MicroGames
 */
UCLASS(Blueprintable)
class DRAGONKISSERST2_API UMicroGameInputComponent final : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	using UEnhancedInputComponent::BindAction;

	DEFINE_BIND_ACTION(TDelegate<void(FVector2D)>);
	DEFINE_BIND_ACTION(TDelegate<void(bool)>);
};