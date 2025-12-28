// Copyright Brigham Young University. All Rights Reserved.


#include "ItemMovementComponent.h"


// Sets default values for this component's properties
UItemMovementComponent::UItemMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UItemMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UItemMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UItemMovementComponent::Launch(FVector LaunchVelocity)
{
	Velocity = LaunchVelocity;

	// SafeMoveUpdatedComponent();
	// SafeMoveUpdatedComponent(Adjusted, UpdatedComponent->GetComponentRotation().Quaternion(), true, Hit);

	UpdateComponentVelocity();
}

