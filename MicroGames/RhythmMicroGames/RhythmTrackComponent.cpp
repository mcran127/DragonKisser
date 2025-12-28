// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmTrackComponent.h"

#include "DanceMicroGame/DanceNote.h"


// Sets default values for this component's properties
ARhythmTrackComponent::ARhythmTrackComponent()
{
	RootComponent = Spawner = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));
	
	Destroyer = CreateDefaultSubobject<UBoxComponent>(TEXT("Destroyer"));
	Destroyer->SetupAttachment(Spawner);
	NoteLane = CreateDefaultSubobject<USplineComponent>(TEXT("NoteLane"));
	NoteLane->SetupAttachment(Spawner);
	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane->SetupAttachment(Spawner);
	SplineTrack = CreateDefaultSubobject<UBoxComponent>(TEXT("SplineTrack"));
	SplineTrack->SetupAttachment(Spawner);
	BackgroundTrack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackgroundTrack"));
	BackgroundTrack->SetupAttachment(Spawner);
	RatingPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RatingPlane"));
	RatingPlane->SetupAttachment(Spawner);
}

void ARhythmTrackComponent::BeginPlay()
{
	Super::BeginPlay();

	if (Destroyer)
	{
		Destroyer->OnComponentBeginOverlap.AddDynamic(this, &ARhythmTrackComponent::OnDestroyerOverlap);
	}
}

void ARhythmTrackComponent::OnDestroyerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ARhythmNote::StaticClass()))
	{
		const ARhythmNote* RhythmNote = Cast<ARhythmNote>(OtherActor);
		OnDestroyOverlap.Broadcast(RhythmNote->NoteValue, 0);

		UpdateRatingMaterial(0);
	}
	OtherActor->Destroy();
}

void ARhythmTrackComponent::UpdateRatingMaterial(int32 Rating)
{
	if (RatingPlane && RatingImages.IsValidIndex(Rating))
	{
		RatingPlane->SetMaterial(0, RatingImages[Rating]);
	}
}
