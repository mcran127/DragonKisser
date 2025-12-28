// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CurtainObject.generated.h"

/**
 * @class ACurtainObject
 *
 * Open and Close Curtain Process. Mostly to make a base class that c++ items can use
 */
UCLASS()
class DRAGONKISSERST2_API ACurtainObject : public AActor
{
	GENERATED_BODY()

public:
	ACurtainObject();
};
