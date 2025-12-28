// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MicroGameMode.generated.h"

class UGameInstanceBase;

/**
 *@class AMicroGameMode
 *
 * Base Game Mode for the microgames
 */
UCLASS()
class DRAGONKISSERST2_API AMicroGameMode : public AGameModeBase
{
public:
	/**
	 * Soft pointers to levels, should remove
	 */
	AMicroGameMode();

private:
	GENERATED_BODY()

protected:
	/**
	 * Sets up player controller and binds to rizz subsystem
	 */
	virtual void BeginPlay() override;
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Instance")
	TObjectPtr<UGameInstanceBase> DragonKisserGameInstance;

	/**
	 * Updates the Stun, Rizz, and Health of the Player as they change level
	 * 
	 * @param bWonGame Boolean if the player won the MicroGame
	 */
	UFUNCTION(BlueprintCallable, Category="GameplayLoop")
	virtual void MoveToMain(bool bWonGame);

	/**
	 * Overridable function focusing on setup of a minigame. Primarily bound from the microgame overlay widget
	 */
	UFUNCTION(Category="GameplayLoop")
	virtual void MicroGameStart();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WinVal")
	double WinVal = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WinVal")
	double LoseVal = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinVal")
	int32 WinHealthVal = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinVal")
	int32 LoseHealthVal = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WinVal")
	bool bWinGame = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StartGameText")
	FString MinigameText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Timer")
	double MinigameTimer = 0.0;

	UFUNCTION(BlueprintCallable)
	void AsyncLevelLoad( const TSoftObjectPtr<UWorld> Level);

	/**
	 * Changes the level to a different microgame or the sideline fight level. Temporary blueprint version
	 * 
	 * @param Index Minigame index of the LevelList
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SwapMode")
	void CheckSwapToMinigame(int Index);

	/**
	 * Changes the level to a different microgame or the sideline fight level.
	 * 
	 * @param Index Minigame index of the LevelList
	 */
	void SwapMinigame(int Index);

	UPROPERTY(EditAnywhere, Category = "Swap Mode")
	TArray<TSoftObjectPtr<UWorld>> LevelList;

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;

private:
	static void AsyncLevelLoadFinished(TSoftObjectPtr<UWorld> Level);
};
