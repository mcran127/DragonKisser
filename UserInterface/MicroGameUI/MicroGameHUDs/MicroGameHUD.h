// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "../../../MicroGames/CurtainObject.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameOverlayWidget.h"
#include "GameFramework/HUD.h"
#include "MicroGameHUD.generated.h"

/**
 *@class AMicroGameHUD
 *
 * MicroGame Base HUD Class
 */
UCLASS()
class DRAGONKISSERST2_API AMicroGameHUD : public AHUD
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "GameplayLoop")
	TSubclassOf<ACurtainObject> OpenCurtainClass;

	UPROPERTY(VisibleAnywhere, Category = "GameplayLoop")
	TObjectPtr<ACurtainObject> OpenCurtainObject;

	UPROPERTY(EditAnywhere, Category = "GameplayLoop")
	TSubclassOf<ACurtainObject> CloseCurtainClass;

	UPROPERTY(VisibleAnywhere, Category = "GameplayLoop")
	TObjectPtr<ACurtainObject> CloseCurtainObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayLoop")
	TSubclassOf<UMicroGameOverlayWidget> MicroGameOverlayClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameplayLoop")
	TObjectPtr<UMicroGameOverlayWidget> MicroGameOverlayWidget;

	/**
	 * Creates a Curtain object from OpenCurtainClass and sets it to OpenCurtainObject, then destroys itself
	 */
	UFUNCTION(Category="GameplayLoop")
	void OpenCurtainProcess();

	/**
	 * Creates a Curtain object from CloseCurtainClass and sets it to CloseCurtainObject, then destroys itself
	 */
	UFUNCTION(Category="GameplayLoop")
	void CloseCurtainProcess();

	/**
	 * Creates a MicroGameOverlayWidget
	 * 
	 * @param PlayerController PlayerController to create widget
	 * @param NewText Text for the MicroGameOverlayWidget
	 * @param NewTimer Timer Duration for the MicroGameOverlayWidget
	 * @return Returns a reference to the newly created widget
	 */
	UFUNCTION(Category="GameplayLoop")
	UMicroGameOverlayWidget* SetupMicroGameOverlay(APlayerController* PlayerController,
		const FString& NewText, float NewTimer);
};