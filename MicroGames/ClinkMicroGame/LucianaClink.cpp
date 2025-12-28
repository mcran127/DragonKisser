// Copyright Brigham Young University. All Rights Reserved.


#include "LucianaClink.h"


// Sets default values
ALucianaClink::ALucianaClink()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = ClinkTriggerComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("ClinkTrigger"));
	ClinkTriggerComponent->SetupAttachment(GlassPlane);

	BlockSphere = CreateDefaultSubobject<USphereComponent>(TEXT("BlockSphere"));
	BlockSphere->SetupAttachment(ClinkTriggerComponent);

	GlassPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GlassPlane"));
	GlassPlane->SetupAttachment(ClinkTriggerComponent);
}
