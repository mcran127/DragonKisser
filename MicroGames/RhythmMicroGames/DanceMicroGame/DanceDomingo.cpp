// Copyright Brigham Young University. All Rights Reserved.


#include "DanceDomingo.h"


// Sets default values
ADanceDomingo::ADanceDomingo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ADanceDomingo::DomingoDanceUp(bool Success)
{
	if (Success)
	{
		SetNewMaterial(0);
	}
	else
	{
		SetNewMaterial(4);
	}
	ReturnToBaseMaterial();
}

void ADanceDomingo::DomingoDanceLeft(bool Success)
{
	if (Success)
	{
		SetNewMaterial(1);
	}
	else
	{
		SetNewMaterial(4);
	}
	ReturnToBaseMaterial();
}

void ADanceDomingo::DomingoDanceRight(bool Success)
{
	if (Success)
	{
		SetNewMaterial(2);
	}
	else
	{
		SetNewMaterial(4);
	}
	ReturnToBaseMaterial();
}

void ADanceDomingo::DomingoDanceDown(bool Success)
{
	if (Success)
	{
		SetNewMaterial(3);
	}
	else
	{
		SetNewMaterial(4);
	}
	ReturnToBaseMaterial();
}

// Called when the game starts or when spawned
void ADanceDomingo::BeginPlay()
{
	Super::BeginPlay();

	IdleMaterialIndex = 5;
	SetNewMaterial(IdleMaterialIndex);
}


