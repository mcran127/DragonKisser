// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CorrectAnswers.h"
#include "UObject/Object.h"
#include "QuestionAnswer.generated.h"

/**
 * @struct FQuestionAnswer
 *
 * Struct consisting of a question and a FCorrectAnswers struct
 */
USTRUCT(BlueprintType)
struct DRAGONKISSERST2_API FQuestionAnswer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Question;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCorrectAnswers> Answers;
};
