// Copyright Brigham Young University. All Rights Reserved.


#include "DanceSpline.h"

#include "NiagaraFunctionLibrary.h"


// Sets default values
ADanceSpline::ADanceSpline()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RhythmTrackComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("RhythmTrack"));
	RhythmTrackComponent->SetupAttachment(RootComponent);

	RhythmOverlapComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("RhythmOverlap"));
	RhythmOverlapComponent->SetupAttachment(RootComponent);

	bCollisionCheckZ = false;
	NoteClass = ADanceNote::StaticClass();
}

// Called when the game starts or when spawned
void ADanceSpline::BeginPlay()
{
	Super::BeginPlay();

	RhythmTrack = Cast<ARhythmTrackComponent>(RhythmTrackComponent->GetChildActor());

	if (RhythmTrack)
	{
		RhythmTrack->OnDestroyOverlap.AddUObject(this, &ADanceSpline::OverlapOrDestroyed);
	}

	if (RhythmOverlap)
	{
		RhythmOverlap->OnNiagara.AddUObject(this, &ADanceSpline::ActivateNiagaraSystem);
	}

	CurrentTrack = 0; //(rand() % 3);
	
	switch (CurrentTrack)
	{
	case 0:
		BeatsPerMinute = 100.0;
		BeatsToWait = 3.0;
		break;
		
	default:
		BeatsPerMinute = 120.0;
		BeatsToWait = 4.0;
	} 

	NoteSpeed = (BeatsPerMinute / (60.0 * BeatsToWait)) * RhythmTrack->NoteLane->GetSplineLength() *  (15.0  / 19.0);
}

void ADanceSpline::UpdateRating(int32 Location, int32 Rating) const
{
	RhythmTrack->UpdateRatingMaterial(Rating);
}

void ADanceSpline::ActivateNiagaraSystem(int32 Location)
{
	if (RhythmBurst)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,
			RhythmBurst,
			RhythmTrack->Plane->GetComponentLocation(),
			FRotator(0.f),
			FVector(0.05f)
			);
	}
}

void ADanceSpline::CueChange(const FName OutputName, const FMetaSoundOutput& Output)
{
	if (CurrentLabel == TEXT("ERROR"))
	{
		UE_LOG(LogTemp, Error, TEXT("Label Change Error: GuitarSpline > CueChange"))
	}

	int32 NoteValue;

	if (CurrentLabel.Equals(TEXT("LEFT")))
	{
		NoteValue = 1;
	}
	else if (CurrentLabel.Equals(TEXT("RIGHT")))
	{
		NoteValue = 3;
	}
	else if (CurrentLabel.Equals(TEXT("UP")))
	{
		NoteValue = 0;
	}
	else if (CurrentLabel.Equals(TEXT("DOWN")))
	{
		NoteValue = 2;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Label Change Error: GuitarSpline > CueChange"))
		return;
	}

	if (ADanceNote* Note = GetWorld()->SpawnActor<ADanceNote>(
		NoteClass,
		RhythmTrack->Spawner->GetComponentToWorld().GetLocation(),
		FRotator(180,0,-90)))
	{
		Note->NoteValue = NoteValue;
		Note->SwapMesh(NoteValue);
		Note->StartMovement(RhythmTrack->NoteLane, NoteSpeed);
	}
}


