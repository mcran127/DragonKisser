// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniGameSpawnLocator.generated.h"

class USplineComponent;

UCLASS()
class DRAGONKISSERST2_API AMiniGameSpawnLocator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMiniGameSpawnLocator();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USplineComponent> SplineComponent;

	UFUNCTION()
	USplineComponent* MakeLaunchArc(const AActor* TargetActor);
};
