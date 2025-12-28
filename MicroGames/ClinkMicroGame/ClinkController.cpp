// Copyright Brigham Young University. All Rights Reserved.


#include "ClinkController.h"
#include "ClinkCharacter.h"


void AClinkController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputSystem->AddMappingContext(CurrentMappingContext, 1);

	CurrentInput->BindAction(Move_Action, ETriggerEvent::Triggered, this, &ThisClass::MoveInputTriggered);
}

void AClinkController::MoveInputTriggered(const FInputActionValue& Value)
{
	if (AClinkCharacter* ClinkCharacter = Cast<AClinkCharacter>(GetPawn()))
	{
		ClinkCharacter->MoveCharacter(Value);
	}
}