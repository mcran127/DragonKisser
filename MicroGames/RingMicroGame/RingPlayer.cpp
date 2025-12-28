// Copyright Brigham Young University. All Rights Reserved.


#include "RingPlayer.h"

#include "InputActionValue.h"
#include "RingController.h"


// Sets default values
ARingPlayer::ARingPlayer()
{
	PrimaryActorTick.bCanEverTick = false;

	CharacterHandPlane = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CharacterHandPlane"));
	CharacterHandPlane->SetupAttachment(RootComponent);

	RingPlaneFront = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("RingPlaneFront"));
	RingPlaneFront->SetupAttachment(RootComponent);

	RingPlaneBack = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("RingPlaneBack"));
	RingPlaneBack->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARingPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (ARingController* RingController = Cast<ARingController>(GetController()))
	{
		RingController->OnMoveRing.AddDynamic(this, &ARingPlayer::MovePlayer);
	}
}

// Called every frame
void ARingPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARingPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARingPlayer::SetRotation(FRotator ToRotate)
{
	if (RingPlaneFront && RingPlaneBack)
	{
		RingPlaneFront->SetRelativeRotation(ToRotate);
		RingPlaneBack->SetRelativeRotation(ToRotate);
	}
}

void ARingPlayer::MovePlayer(const FInputActionValue& Value)
{
	const FVector2D MoveInput = Value.Get<FVector2D>();

	FRotator CurrentRotation = GetControlRotation();
	CurrentRotation.Pitch = 0;
	AddMovementInput(CurrentRotation.Vector(), MoveInput.X);

	CurrentRotation.Roll = 0;
	AddMovementInput(FRotationMatrix(CurrentRotation).GetScaledAxis(EAxis::Z), MoveInput.Y);
}

