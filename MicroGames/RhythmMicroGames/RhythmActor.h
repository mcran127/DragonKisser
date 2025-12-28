// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RhythmActor.generated.h"

/**
 * @class ARhythmActor
 *
 * Abstract class for rhythm game dancing actors
 */
UCLASS(Abstract)
class DRAGONKISSERST2_API ARhythmActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARhythmActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> RhythmPlane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TArray<TObjectPtr<UMaterial>> AllMaterials;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delay")
	float Delay = .25;

protected:
	virtual void BeginPlay() override;

	/**
	 * Check if valid material, if so adjust based on AllMaterials
	 * 
	 * @param NewMaterial Index in AllMaterials to change to
	 */
	void SetNewMaterial(int32 NewMaterial);

	/**
	 * After a moment, set material to idle
	 */
	UFUNCTION()
	void ReturnToBaseMaterial();

	int32 IdleMaterialIndex = 0;
};
