// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/HUD.h"
#include "DragonKisserST2/MicroGames/CprMicroGame/CprWidget.h"
#include "DragonKisserST2/UserInterface/PlayerPromptWidget.h"
#include "DragonKisserST2/UserInterface/MainUIWidget.h"
#include "ControlHUD.generated.h"

class UMainUIWidget;
class UPlayerPromptWidget;
class UCprWidget;
/**
 * Primary HUD
 */
UCLASS(Abstract)
class DRAGONKISSERST2_API AControlHUD : public AHUD
{
	GENERATED_BODY()

	AControlHUD();

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UMainUIWidget> MainUI;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UMainUIWidget> MainWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UPlayerPromptWidget> PlayerNotificationUI;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UPlayerPromptWidget> PlayerNotificationWidget;

	/// widget class for cpr
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UCprWidget> CprUI;
	/// reference to cpr object
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UCprWidget> CprWidget;

	/// create widget for cpr minigame
	UFUNCTION(BlueprintCallable)
	void StartCpr();
	/// called when cpr finishes
	UFUNCTION(BlueprintCallable)
	void EndCpr();
	/// takes input from the player controller
	void CprInput() const;
	
};
