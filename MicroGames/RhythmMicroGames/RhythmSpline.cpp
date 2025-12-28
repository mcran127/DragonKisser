// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmSpline.h"

#include "MetasoundSource.h"
#include "MetasoundOutputSubsystem.h"
#include "Components/AudioComponent.h"

// Sets default values
ARhythmSpline::ARhythmSpline()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnLabelChange.BindDynamic(this, &ThisClass::LabelChange);
	OnCueChange.BindDynamic(this, &ThisClass::CueChange);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("SoundComponent"));
	AudioComponent->SetupAttachment(RootComponent);
}

void ARhythmSpline::AudioFinishedEvent()
{
	OnAudioFinished.Broadcast();
}

void ARhythmSpline::SetupSound()
{
	if (MetaSoundTrack)
	{
		AudioComponent->SetSound(MetaSoundTrack);

		UMetaSoundOutputSubsystem* MetaSoundSubsystem = GetWorld()->GetSubsystem<UMetaSoundOutputSubsystem>();
		MetaSoundSubsystem->WatchOutput(AudioComponent, TEXT("onLabel"), OnLabelChange);
		MetaSoundSubsystem->WatchOutput(AudioComponent, TEXT("onCue"), OnCueChange);

		AudioComponent->OnAudioFinished.AddDynamic(this, &ThisClass::AudioFinishedEvent);
		AudioComponent->Play();
	}
}

// Called when the game starts or when spawned
void ARhythmSpline::BeginPlay()
{
	Super::BeginPlay();

	RhythmOverlap = Cast<ARhythmOverlap>(RhythmOverlapComponent->GetChildActor());

	if (RhythmOverlap)
	{
		RhythmOverlap->OnOverlap.AddUObject(this, &ARhythmSpline::OverlapOrDestroyed);
	}

	SetupSound();
}

void ARhythmSpline::OverlapOrDestroyed(int32 NoteValue, int32 Rating)
{
	OnOverlapOrDestroyed.Broadcast(NoteValue, Rating);
}

void ARhythmSpline::LabelChange(const FName OutputName, const FMetaSoundOutput& Output)
{
	if (FString Value; Output.Get<FString>(Value))
	{
		CurrentLabel = Value;
	}
	else
	{
		CurrentLabel = TEXT("ERROR");
	}
}

void ARhythmSpline::CueChange(const FName OutputName, const FMetaSoundOutput& Output)
{
}

void ARhythmSpline::ActivateNiagaraSystem(int32 Location)
{
}

void ARhythmSpline::CollisionCheck(int32 Value) const
{
	RhythmOverlap->CollisionCheck(Value, bCollisionCheckZ);
}

void ARhythmSpline::OnRelease()
{
	//Plane->SetMaterial
}

