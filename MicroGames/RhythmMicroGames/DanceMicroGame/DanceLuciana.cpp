// Copyright Brigham Young University. All Rights Reserved.


#include "DanceLuciana.h"


// Sets default values
ADanceLuciana::ADanceLuciana()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ADanceLuciana::LucianaDance(int32 index)
{
	SetNewMaterial(index);
	ReturnToBaseMaterial();
}

// Called when the game starts or when spawned
void ADanceLuciana::BeginPlay()
{
	Super::BeginPlay();

	IdleMaterialIndex = 4;
	SetNewMaterial(IdleMaterialIndex);
}


