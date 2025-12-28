// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmOverlap.h"

#include "NiagaraFunctionLibrary.h"
#include "DanceMicroGame/DanceNote.h"


// Sets default values
ARhythmOverlap::ARhythmOverlap()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
}

void ARhythmOverlap::CollisionCheck(int32 Key, bool bCollisionCheckZ)
{
	TArray<AActor*> OverlappingBox;
	if (OverlapBox->GetOverlappingActors(OverlappingBox, ARhythmNote::StaticClass()); !OverlappingBox.IsEmpty())
	{
		ARhythmNote* OverlappingNote = Cast<ARhythmNote>(OverlappingBox[0]);
		if (OverlappingNote->NoteValue != Key)
		{
			OnOverlap.Broadcast(OverlappingNote->NoteValue, 0);
			OverlappingNote->Destroy();
			return;
		}
		
		float NoteDist;
		if (bCollisionCheckZ)
		{
			NoteDist = abs(OverlappingNote->GetActorLocation().Z - OverlapBox->GetComponentLocation().Z);
		}
		else
		{
			NoteDist = (OverlappingNote->GetActorLocation() - OverlapBox->GetComponentLocation()).Length();
		}

		if (NoteDist < PerfectCollisionThreshold)
		{
			OnNiagara.Broadcast(OverlappingNote->NoteValue);
			OverlappingNote->Destroy();
			OnOverlap.Broadcast(OverlappingNote->NoteValue, 1);
			return;
		}
		if (NoteDist < GoodCollisionThreshold)
		{
			OnNiagara.Broadcast(OverlappingNote->NoteValue);
			OverlappingNote->Destroy();
			OnOverlap.Broadcast(OverlappingNote->NoteValue, 2);
			return;
		}
		if (NoteDist < OkCollisionThreshold)
		{
			OnNiagara.Broadcast(OverlappingNote->NoteValue);
			OverlappingNote->Destroy();
			OnOverlap.Broadcast(OverlappingNote->NoteValue, 3);
			return;
		}
		OverlappingNote->Destroy();
		OnOverlap.Broadcast(OverlappingNote->NoteValue, 0);
	}
	else
	{
		OnOverlap.Broadcast(-1, 4);
	}
}

// Called when the game starts or when spawned
void ARhythmOverlap::BeginPlay()
{
	Super::BeginPlay();
}


