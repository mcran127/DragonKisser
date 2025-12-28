// Copyright Brigham Young University. All Rights Reserved.


#include "LucianaSpline.h"

#include "EngineUtils.h"


// Sets default values
ALucianaSpline::ALucianaSpline()
{
	PrimaryActorTick.bCanEverTick = true;

	RhythmTrackComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("RhythmTrack"));
	RhythmTrackComponent->SetupAttachment(RootComponent);

	RhythmOverlapComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("RhythmOverlap"));
	RhythmOverlapComponent->SetupAttachment(RootComponent);

	NoteClass = ADanceNote::StaticClass();
}

void ALucianaSpline::BeginPlay()
{
	Super::BeginPlay();

	RhythmTrack = Cast<ARhythmTrackComponent>(RhythmTrackComponent->GetChildActor());

	if (ADanceLuciana::StaticClass())
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull))
		{
			for (TActorIterator<AActor> It(World, ADanceLuciana::StaticClass()); It; ++It)
			{
				DanceLuciana = Cast<ADanceLuciana>(*It);
			}
		}
	}

	if (RhythmOverlapComponent)
	{
		if (const ARhythmOverlap* RhythmOverlapObject = Cast<ARhythmOverlap>(RhythmOverlapComponent->GetChildActor()))
		{
			RhythmOverlapObject->OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &ALucianaSpline::OnNoteOverlap);
		}
	}

	CurrentTrack = 0;
	
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

void ALucianaSpline::OnNoteOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const ADanceNote* DanceNote = Cast<ADanceNote>(OtherActor))
	{
		DanceLuciana->LucianaDance(DanceNote->NoteValue);
	}
	OtherActor->Destroy();
}

void ALucianaSpline::CueChange(const FName OutputName, const FMetaSoundOutput& Output)
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
		FRotator::ZeroRotator))
	{
		Note->NoteValue = NoteValue;
		Note->SwapMesh(NoteValue);
		Note->StartMovement(RhythmTrack->NoteLane, NoteSpeed);
	}
}


