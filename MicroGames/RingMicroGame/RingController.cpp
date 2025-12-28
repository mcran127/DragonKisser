// Copyright Brigham Young University. All Rights Reserved.


#include "RingController.h"

void ARingController::BeginPlay()
{
	Super::BeginPlay();

	InputSystem->AddMappingContext(CurrentMappingContext, 0);

	CurrentInput->BindAction(Move_Action, ETriggerEvent::Triggered, this, &ThisClass::MoveRing);
}

void ARingController::MoveRing(const FInputActionValue& Value)
{
	OnMoveRing.Broadcast(Value);
}
