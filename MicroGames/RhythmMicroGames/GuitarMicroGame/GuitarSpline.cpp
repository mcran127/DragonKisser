// Copyright Brigham Young University. All Rights Reserved.


#include "GuitarSpline.h"
#include "GuitarNote.h"
#include "MetasoundOutputSubsystem.h"
#include "NiagaraFunctionLibrary.h"


AGuitarSpline::AGuitarSpline()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RhythmOverlapComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("RhythmOverlap"));
	RhythmOverlapComponent->SetupAttachment(RootComponent);

	TrackLeftComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("TrackLeft"));
	TrackLeftComponent->SetupAttachment(RootComponent);
	
	TrackUpComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("TrackUp"));
	TrackUpComponent->SetupAttachment(RootComponent);
	
	TrackDownComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("TrackDown"));
	TrackDownComponent->SetupAttachment(RootComponent);

	TrackRightComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("TrackRight"));
	TrackRightComponent->SetupAttachment(RootComponent);
	
	bCollisionCheckZ = true;
	NoteClass = AGuitarNote::StaticClass();

}

void AGuitarSpline::BeginPlay()
{
	Super::BeginPlay();
	
	TrackLeft = Cast<ARhythmTrackComponent>(TrackLeftComponent->GetChildActor());
	TrackUp = Cast<ARhythmTrackComponent>(TrackUpComponent->GetChildActor());
	TrackDown = Cast<ARhythmTrackComponent>(TrackDownComponent->GetChildActor());
	TrackRight = Cast<ARhythmTrackComponent>(TrackRightComponent->GetChildActor());

	if (TrackLeft)
	{
		TrackLeft->OnDestroyOverlap.AddUObject(this, &AGuitarSpline::OverlapOrDestroyed);
	}
	if (TrackUp)
	{
		TrackUp->OnDestroyOverlap.AddUObject(this, &AGuitarSpline::OverlapOrDestroyed);
	}
	if (TrackDown)
	{
		TrackDown->OnDestroyOverlap.AddUObject(this, &AGuitarSpline::OverlapOrDestroyed);
	}
	if (TrackRight)
	{
		TrackRight->OnDestroyOverlap.AddUObject(this, &AGuitarSpline::OverlapOrDestroyed);
	}

	if (RhythmOverlap)
	{
		RhythmOverlap->OnOverlap.AddUObject(this, &AGuitarSpline::UpdateRating);
		RhythmOverlap->OnNiagara.AddUObject(this, &AGuitarSpline::ActivateNiagaraSystem);
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

	NoteSpeed = (BeatsPerMinute / (60.0 * BeatsToWait)) * TrackLeft->NoteLane->GetSplineLength() *  (15.0  / 19.0);
}


void AGuitarSpline::CueChange(const FName OutputName, const FMetaSoundOutput& Output)
{
	if (CurrentLabel == TEXT("ERROR"))
	{
		UE_LOG(LogTemp, Error, TEXT("Label Change Error: GuitarSpline > CueChange"))
	}

	int32 NoteValue;
	double PitchRotation;
	ARhythmTrackComponent* Track;

	if (CurrentLabel.Equals(TEXT("LEFT")))
	{
		Track = TrackLeft;
		NoteValue = 0;
		PitchRotation = -90.0;
	}
	else if (CurrentLabel.Equals(TEXT("RIGHT")))
	{
		Track = TrackRight;
		NoteValue = 3;
		PitchRotation = 90.0;
	}
	else if (CurrentLabel.Equals(TEXT("UP")))
	{
		Track = TrackUp;
		NoteValue = 1;
		PitchRotation = 0.0;
	}
	else if (CurrentLabel.Equals(TEXT("DOWN")))
	{
		Track = TrackDown;
		NoteValue = 2;
		PitchRotation = 180.0;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Label Change Error: GuitarSpline > CueChange"))
		return;
	}
	
	SpawnNote(Track->NoteLane, Track->Spawner->GetComponentToWorld().GetLocation(), FRotator(PitchRotation, 0.0, -90.0), NoteValue);
}

void AGuitarSpline::SpawnNote(USplineComponent* Lane, const FVector SpawnLocation, const FRotator SpawnRotation, const int32 NoteValue) const
{
	if (AGuitarNote* Note = GetWorld()->SpawnActor<AGuitarNote>(NoteClass, SpawnLocation, SpawnRotation))
	{
		Note->NoteValue = NoteValue;
		Note->StartMovement(Lane, NoteSpeed);
		return;
	}
	UE_LOG(LogTemp, Display, TEXT("Failed to create note"));
}

void AGuitarSpline::ActivateNiagaraSystem(int32 Location)
{
	FVector NiagaraLocation = FVector::ZeroVector;
	switch (Location)
	{
	case 0:
		NiagaraLocation = TrackLeft->Plane->GetComponentLocation();
		break;
	case 1:
		NiagaraLocation = TrackUp->Plane->GetComponentLocation();
		break;
	case 2:
		NiagaraLocation = TrackDown->Plane->GetComponentLocation();
		break;
	case 3:
		NiagaraLocation = TrackRight->Plane->GetComponentLocation();
		break;
	default:
		break;
	}
	
	if (RhythmBurst)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			this,
			RhythmBurst,
			NiagaraLocation,
			FRotator(0.f),
			FVector(0.05f)
			);
	}
}

void AGuitarSpline::UpdateRating(const int32 Location, const int32 Rating) const
{
	switch (Location)
	{
	case 0:
		TrackLeft->UpdateRatingMaterial(Rating);
		break;
	case 1:
		TrackUp->UpdateRatingMaterial(Rating);
		break;
	case 2:
		TrackDown->UpdateRatingMaterial(Rating);
		break;
	case 3:
		TrackRight->UpdateRatingMaterial(Rating);
		break;
	default:
		break;
	}
}


