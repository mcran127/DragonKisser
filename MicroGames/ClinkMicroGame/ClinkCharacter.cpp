// Copyright Brigham Young University. All Rights Reserved.


#include "ClinkCharacter.h"


// Sets default values
AClinkCharacter::AClinkCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GlassPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GlassPlane"));
	GlassPlane->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AClinkCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AClinkCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AClinkCharacter::MoveCharacter(const FInputActionValue& Value)
{
	FRotator CurrRotation = GetControlRotation();
	
	CurrRotation.Pitch = 0;
	const FVector ForwardVector = CurrRotation.Vector();
	AddMovementInput(ForwardVector, Value.Get<FVector2D>().X * 5000000, false);

	CurrRotation.Roll = 0;
	const FVector UpVector = FRotationMatrix(CurrRotation).GetScaledAxis(EAxis::Z);
	AddMovementInput(UpVector, Value.Get<FVector2D>().Y * 5000000, false);
}

