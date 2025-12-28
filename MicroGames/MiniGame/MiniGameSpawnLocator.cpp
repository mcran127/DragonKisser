// Copyright Brigham Young University. All Rights Reserved.


#include "MiniGameSpawnLocator.h"

#include "Components/SplineComponent.h"


// Sets default values
AMiniGameSpawnLocator::AMiniGameSpawnLocator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline");
	SplineComponent->SetUsingAbsoluteLocation(true);
}

USplineComponent* AMiniGameSpawnLocator::MakeLaunchArc(const AActor* TargetActor)
{
	SplineComponent->ClearSplinePoints();
	SplineComponent->AddSplineWorldPoint(GetActorLocation());
	SplineComponent->AddSplineWorldPoint(TargetActor->GetActorLocation());

	FRotator TempR = SplineComponent->GetSplinePointAt(0, ESplineCoordinateSpace::World).Rotation;
	TempR = FRotator(TempR.Pitch + 45.0, TempR.Yaw, TempR.Roll);
	SplineComponent->SetRotationAtSplinePoint(0, TempR, ESplineCoordinateSpace::World);

	TempR = SplineComponent->GetSplinePointAt(1, ESplineCoordinateSpace::World).Rotation;
	TempR = FRotator(TempR.Pitch - 60.0, TempR.Yaw, TempR.Roll);
	SplineComponent->SetRotationAtSplinePoint(1, TempR, ESplineCoordinateSpace::World);
	
	return SplineComponent;
}


