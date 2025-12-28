// Copyright Brigham Young University. All Rights Reserved.


#include "MicroGameController.h"

#include "MicroGameInputComponent.h"

void AMicroGameController::SetupInputComponent()
{
	checkf(!InputComponent, TEXT("input component already set up"));
	
	InputComponent = CurrentInput = NewObject<UMicroGameInputComponent>(this, TEXT("InputComponent"));
	if (CurrentInput)
	{
		CurrentInput->RegisterComponent();
	}

	InputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	checkf(InputSystem, TEXT("Failed to Get EnhancedInputLocalPlayerSubsystem"));
}
