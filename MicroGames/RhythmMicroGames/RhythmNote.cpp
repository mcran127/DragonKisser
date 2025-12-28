// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmNote.h"


// Sets default values
ARhythmNote::ARhythmNote()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("NoteMesh"));
}

void ARhythmNote::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bMoving)
	{
		DistanceAlongSpline += DeltaSeconds * NoteRate;
		
		FVector Location = Lane->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
		
		SetActorLocation(Location);
		
	}
}

void ARhythmNote::StartMovement(USplineComponent* NewLane, float NoteSpeed)
{
	Lane = NewLane;
	NoteRate = NoteSpeed;
	bMoving = true;
}
