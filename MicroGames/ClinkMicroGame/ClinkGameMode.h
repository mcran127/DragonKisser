// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LucianaClink.h"
#include "DragonKisserST2/MicroGames/MicroGameMode.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/MicroGameHUD.h"
#include "ClinkGameMode.generated.h"

/**
 * @class AClinkGameMode
 *
 * Game Mode for Clink Micro Game
 */
UCLASS()
class DRAGONKISSERST2_API AClinkGameMode : public AMicroGameMode
{
	GENERATED_BODY()

	/**
	 * Calls super Begin Play, disables movement and prepares the microgame widget
	 */
	virtual void BeginPlay() override;

	/**
	 * Activates move input and spawns Luciana clink actor
	 */
	virtual void MicroGameStart() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AMicroGameHUD> MicroGameHUD;

public:
	/**
	 * Calls the microgame widget to display win or loss text and ends the game
	 */
	UFUNCTION(BlueprintCallable, Category="EndGame")
	void DisplayEndText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EndGame")
	FString GameEndTextWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EndGame")
	FString GameEndTextLose;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LucianaClink")
	TSubclassOf<ALucianaClink> LucianaClass;

protected:
	/**
	 * calls close curtain process
	 * 
	 * @param bWon Did the player win?
	 */
	UFUNCTION(Category="EndGame")
	void EndClinkGame(bool bWon);
};
