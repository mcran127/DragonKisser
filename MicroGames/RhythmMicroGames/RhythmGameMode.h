// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameMode.h"
#include "RhythmGameMode.generated.h"

/**
 * @class ARhythmGameMode
 *
 * Game Mode for Dance and Guitar MicroGames
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmGameMode : public AMicroGameMode
{
	GENERATED_BODY()

	/**
	 * Stops main game sound and creates rhythm and curtain widgets
	 */
	virtual void BeginPlay() override;
};
