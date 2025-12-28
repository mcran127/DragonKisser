// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameMode.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/MicroGameHUD.h"
#include "RingGameMode.generated.h"

/**
 * @class ARingGameMode
 *
 * Game Mode for Ring Micro Game
 */
UCLASS()
class DRAGONKISSERST2_API ARingGameMode : public AMicroGameMode
{
	GENERATED_BODY()

	/**
	 * Calls super Begin Play, disables movement and prepares the microgame widget
	 */
	virtual void BeginPlay() override;

	/**
	 * Calls if the time runs out
	 */
	void TimerEnd();

	/**
	 * Activates move input
	 */
	virtual void MicroGameStart() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AMicroGameHUD> MicroGameHUD;

	UPROPERTY(EditAnywhere)
	FText TimerEndText;
	
public:
	/**
	 * Calls the microgame widget to display win or loss text
	 * 
	 * @param bWon Did the player win?
	 */
	UFUNCTION(BlueprintCallable, Category="EndGame")
	void DisplayEndText(bool bWon);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EndGame")
	FString GameEndTextWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EndGame")
	FString GameEndTextLose;

protected:
	/**
	 * calls close curtain process
	 * 
	 * @param bWon Did the player win?
	 */
	UFUNCTION(Category="EndGame")
	void EndRingGame(bool bWon);
};
