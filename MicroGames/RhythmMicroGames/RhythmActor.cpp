// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmActor.h"


// Sets default values
ARhythmActor::ARhythmActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = RhythmPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DancePlane"));
}

void ARhythmActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARhythmActor::SetNewMaterial(int32 NewMaterial)
{
	if (RhythmPlane && RhythmPlane->GetMaterial(0) && AllMaterials.IsValidIndex(NewMaterial))
	{
		RhythmPlane->SetMaterial(0, AllMaterials[NewMaterial]);
	}
}

void ARhythmActor::ReturnToBaseMaterial()
{
	FTimerHandle TimerHandle;

	TWeakObjectPtr WeakThis(this);
	GetWorldTimerManager().SetTimer(
	TimerHandle,
	[WeakThis]
	{
		if (!WeakThis.IsValid()) {return;}

		ARhythmActor* RhythmActor = Cast<ARhythmActor>(WeakThis.Get());
		RhythmActor->SetNewMaterial(RhythmActor->IdleMaterialIndex);
	},
	Delay,
	false);
}


