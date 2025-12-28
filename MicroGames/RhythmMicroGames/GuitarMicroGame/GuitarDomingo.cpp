// Copyright Brigham Young University. All Rights Reserved.


#include "GuitarDomingo.h"


// Sets default values
AGuitarDomingo::AGuitarDomingo()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGuitarDomingo::DomingoGuitar(bool Success)
{
	if (Success)
	{
		SetNewMaterial(1);
	}
	else
	{
		SetNewMaterial(2);
	}
	ReturnToBaseMaterial();
}

void AGuitarDomingo::BeginPlay()
{
	Super::BeginPlay();
	
	IdleMaterialIndex = 0;
	SetNewMaterial(0);
}
