// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmNote.h"
#include "GameFramework/Actor.h"
#include "GuitarNote.generated.h"

/**
 * @class AGuitarNote
 *
 * Child of ARhythmNote for the Guitar Minigame, exists just in case for additional functionality
 */
UCLASS()
class DRAGONKISSERST2_API AGuitarNote : public ARhythmNote
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGuitarNote();

};
