// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CorrectAnswers.generated.h"

/**
 * @struct FCorrectAnswers
 *
 * Answer struct for the dating sim consisting of an answer, a response, and a correct boolean
 */
USTRUCT(BlueprintType)
struct DRAGONKISSERST2_API FCorrectAnswers
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Answer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCorrect = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LucianaResponse;
};
