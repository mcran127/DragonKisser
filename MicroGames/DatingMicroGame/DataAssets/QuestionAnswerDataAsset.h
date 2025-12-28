// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestionAnswer.h"
#include "Engine/DataAsset.h"
#include "QuestionAnswerDataAsset.generated.h"

/**
 * @class UQuestionAnswerDataAsset
 *
 * Primary Data Asset class for the Dating Sim
 */
UCLASS()
class DRAGONKISSERST2_API UQuestionAnswerDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestionAnswer> QuestionAnswersArray;
};
