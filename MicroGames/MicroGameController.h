// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "MicroGameController.generated.h"

/**
 * @class AMicroGameController
 *
 * Base Class for Microgame Controllers
 */
UCLASS()
class DRAGONKISSERST2_API AMicroGameController : public APlayerController
{
	GENERATED_BODY()

protected:
	/**
	 * Sets up Input component with preset mapping context, called by children controllers
	 */
	virtual void SetupInputComponent() override;

	UPROPERTY()
	TObjectPtr<UEnhancedInputComponent> CurrentInput;

	UPROPERTY()
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TObjectPtr<UInputMappingContext> CurrentMappingContext;
};
