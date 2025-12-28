// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmActor.h"
#include "GameFramework/Actor.h"
#include "DanceLuciana.generated.h"

/**
 * @class ADanceLuciana
 *
 * Luciana Dance Actor in Dance Microgame
 */
UCLASS()
class DRAGONKISSERST2_API ADanceLuciana : public ARhythmActor
{
	GENERATED_BODY()

public:
	/**
	 * Creates Plane Mesh
	 */
	ADanceLuciana();
	
	/**
	 * Adjust material to the correct dance material, then revert to idle
	 * 
	 * @param index Which Value to switch to?
	 */
	UFUNCTION(BlueprintCallable)
	void LucianaDance(int32 index);

protected:
	/**
	 * Initialize to material index 4 on AllMaterials
	 */
	virtual void BeginPlay() override;
};
