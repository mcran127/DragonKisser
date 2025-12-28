// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DragonKisserST2GameModeBase.generated.h"


class AMiniGameSpawnLocator;
class AMinigameItem;
class AMiniGameLocator;
/**
 * 
 */
UCLASS()
class DRAGONKISSERST2_API ADragonKisserST2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	/**
	 * Swap to the given level via index
	 * @param ToSwap The Index of the level to be swapped to
	 */
	UFUNCTION(BlueprintNativeEvent, Category="SwapMode")
	void SwapToNewLevel(int ToSwap);

	/**
	 * Spawn the correct minigame item
	 * @param Index Pick the correct minigame item
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="SwapMode")
	void CheckSwapToMinigame(int Index);

	/**
	 * Spawn minigame item
	 * @param SetupIndex index of the mesh for the item to use
	 * @param ItemClass class of minigame item to spawn
	 */
	UFUNCTION(BlueprintCallable, Category="MiniGames")
	void SpawnMinigameItem(int SetupIndex, TSubclassOf<AMinigameItem> ItemClass);

	/// Spawn Spotlight
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Spotlight")
	void SpawnSpotlight();

	/**
	 * called when spotlight is finished
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Spotlight")
	void SetSpotlightFinished();


	/// broadcast when cpr starts
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStartCpr);
	FStartCpr OnStartCpr;
	/// broadcast when cpr fails
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFailCpr);
	FFailCpr OnFailCpr;
	/// broadcast when cpr succeeds
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSucceedCpr);
	FSucceedCpr OnSucceedCpr;

	/// called when cpr starts
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cpr")
	void StartCpr();
	/// called when cpr succeeds
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cpr")
	void SucceedCpr();
	/// called when cpr fails
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Cpr")
	void FailCpr();

private:

	/// bool for if a minigame item exists
	UPROPERTY(BlueprintReadWrite, Category="MiniGames", meta=(AllowPrivateAccess="true"))
	bool bMiniGameItemExists = false;
	/// Set bMiniGameItemExists to false
	UFUNCTION() 
	void SetNoMiniGameExists() { bMiniGameItemExists = false; };

	/// Class of the minigame locator
	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess="true", Category="MiniGames"))
	TSubclassOf<AMiniGameLocator> MiniGameLocatorClass;
	/// list of minigame actors
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess="true", Category="MiniGames"))
	TArray<AActor*> MiniGameLocations;

	/// class of minigame spawn locator
	UPROPERTY(EditDefaultsOnly, meta=(AllowPrivateAccess="true", Category="MiniGames"))
    TSubclassOf<AMiniGameSpawnLocator> MiniGameSpawnLocationClass;
	/// minigame spawn locator actor
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess="true", Category="MiniGames"))
	TObjectPtr<AMiniGameSpawnLocator> MiniGameSpawnLocation;

};
