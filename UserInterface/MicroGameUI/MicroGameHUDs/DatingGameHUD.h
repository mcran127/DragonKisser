// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/MicroGameHUD.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/DatingSimMicroGame/DatingSimWidget.h"
#include "DatingGameHUD.generated.h"

class UDatingBackground;
/**
 * @class ADatingGameHUD
 *
 * Primary HUD for the dating microgame
 */
UCLASS()
class DRAGONKISSERST2_API ADatingGameHUD : public AMicroGameHUD
{
	GENERATED_BODY()

	/**
	 * Creates Dating Background widget and opens curtains
	 */
	virtual void BeginPlay() override;

	/**
	 * Calls Button pressed on the Dating Game Mode
	 */
	void ButtonPressed() const;

public:
	UPROPERTY(EditAnywhere, Category="Dating")
	TSubclassOf<UDatingBackground> DatingBackgroundClass;

	UPROPERTY(VisibleAnywhere, Category="Dating")
	TObjectPtr<UDatingBackground> DatingBackgroundObject;

	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UDatingSimWidget> DatingSimWidgetClass;

	UPROPERTY(VisibleAnywhere, Category="Widget")
	TObjectPtr<UDatingSimWidget> DatingSimWidget;

	/**
	 * Creates DatingSimWidget and binds to Button Pressed
	 */
	void SetupDatingWidget();
};
