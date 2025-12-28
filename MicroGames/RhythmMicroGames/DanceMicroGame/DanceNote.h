// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/RhythmMicroGames/RhythmNote.h"
#include "GameFramework/Actor.h"
#include "DanceNote.generated.h"

/**
 * Note class for Dance Minigame
 */
UCLASS()
class DRAGONKISSERST2_API ADanceNote : public ARhythmNote
{
	GENERATED_BODY()

public:
	ADanceNote();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TArray<TObjectPtr<UMaterial>> MaterialList;

	/**
	 * Adjust plane based on MaterialList
	 * 
	 * @param Index Material List Index
	 */
	UFUNCTION(Category = "Visual")
	void SwapMesh(int32 Index);
};