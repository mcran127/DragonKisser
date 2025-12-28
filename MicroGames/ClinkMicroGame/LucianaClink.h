// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "LucianaClink.generated.h"

/**
 * @class ALucianaClink
 *
 * Goal/Luciana's Actor for the Clink MicroGame
 */

UCLASS()
class DRAGONKISSERST2_API ALucianaClink : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Initialize Visuals and Collision
	 */
	ALucianaClink();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> GlassPlane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<USphereComponent> BlockSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UChildActorComponent> ClinkTriggerComponent;
};
