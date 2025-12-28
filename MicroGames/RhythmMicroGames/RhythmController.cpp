// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void ARhythmController::BeginPlay()
{
	Super::BeginPlay();
	
	InputSystem->AddMappingContext(CurrentMappingContext, 0);

	CurrentInput->BindAction(Dance_First, ETriggerEvent::Started, this, &ThisClass::DanceFirst);
	CurrentInput->BindAction(Dance_Second, ETriggerEvent::Started, this, &ThisClass::DanceSecond);
	CurrentInput->BindAction(Dance_Third, ETriggerEvent::Started, this, &ThisClass::DanceThird);
	CurrentInput->BindAction(Dance_Fourth, ETriggerEvent::Started, this, &ThisClass::DanceFourth);

	CurrentInput->BindAction(Dance_First, ETriggerEvent::Completed, this, &ThisClass::DanceFirstEnd);
	CurrentInput->BindAction(Dance_Second, ETriggerEvent::Completed, this, &ThisClass::DanceSecondEnd);
	CurrentInput->BindAction(Dance_Third, ETriggerEvent::Completed, this, &ThisClass::DanceThirdEnd);
	CurrentInput->BindAction(Dance_Fourth, ETriggerEvent::Completed, this, &ThisClass::DanceFourthEnd);
}

void ARhythmController::DanceFirst()
{
	OnFirstPress.Broadcast();
}

void ARhythmController::DanceFirstEnd()
{
	OnFirstRelease.Broadcast();
}

void ARhythmController::DanceThird()
{
	OnThirdPress.Broadcast();
}

void ARhythmController::DanceThirdEnd()
{
	OnThirdRelease.Broadcast();
}

void ARhythmController::DanceSecond()
{
	OnSecondPress.Broadcast();
}

void ARhythmController::DanceSecondEnd()
{
	OnSecondRelease.Broadcast();
}

void ARhythmController::DanceFourth()
{
	OnFourthPress.Broadcast();
}

void ARhythmController::DanceFourthEnd()
{
	OnFourthRelease.Broadcast();
}
