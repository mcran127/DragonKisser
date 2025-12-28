// Copyright Brigham Young University. All Rights Reserved.


#include "RingTrigger.h"

#include "RingGameMode.h"
#include "RingPlayer.h"


// Sets default values
ARingTrigger::ARingTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	BlockBox1 = CreateDefaultSubobject<UBoxComponent>("BlockBox1");
	BlockBox1->SetupAttachment(RootComponent);
	
	BlockBox2 = CreateDefaultSubobject<UBoxComponent>("BlockBox2");
	BlockBox2->SetupAttachment(RootComponent);

	RotationBox = CreateDefaultSubobject<UBoxComponent>("RotationBox");
	RotationBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARingTrigger::BeginPlay()
{
	Super::BeginPlay();

	if (RotationBox)
	{
		RotationBox->OnComponentBeginOverlap.AddDynamic(this, &ARingTrigger::OnRotationBoxBeginOverlap);
		RotationBox->OnComponentEndOverlap.AddDynamic(this, &ARingTrigger::OnRotationBoxEndOverlap);
	}
}

void ARingTrigger::OnRotationBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ARingPlayer* RingPlayer = Cast<ARingPlayer>(OtherActor))
	{
		RingPlayer->SetRotation(ToRotate);
	}
}

void ARingTrigger::OnRotationBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ARingPlayer* RingPlayer = Cast<ARingPlayer>(OtherActor))
	{
		RingPlayer->SetRotation(FRotator::ZeroRotator);
	}
}

void ARingTrigger::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ARingGameMode* RingGameMode = Cast<ARingGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (OtherActor->IsA(ARingPlayer::StaticClass()))
		{
			RingGameMode->DisplayEndText(bPlayerWin);
		}
	}
}


