// Copyright Brigham Young University. All Rights Reserved.


#include "MicroGameTrigger.h"


AMicroGameTrigger::AMicroGameTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
}

void AMicroGameTrigger::BeginPlay()
{
	Super::BeginPlay();

	if (TriggerBox)
	{
		TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AMicroGameTrigger::OnBoxBeginOverlap);
		TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AMicroGameTrigger::OnBoxEndOverlap);
	}
}

void AMicroGameTrigger::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AMicroGameTrigger::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

