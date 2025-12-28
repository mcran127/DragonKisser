// Copyright Brigham Young University. All Rights Reserved.


#include "DatingGameHUD.h"

#include "Blueprint/UserWidget.h"
#include "DragonKisserST2/MicroGames/DatingMicroGame/DatingGameMode.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/DatingSimMicroGame/DatingBackground.h"

void ADatingGameHUD::BeginPlay()
{
	if (DatingBackgroundClass)
	{
		DatingBackgroundObject = Cast<UDatingBackground>(CreateWidget(GetOwningPlayerController(), DatingBackgroundClass));
		DatingBackgroundObject->AddToViewport(-1);
	}

	OpenCurtainProcess();
}

void ADatingGameHUD::ButtonPressed() const
{
	const ADatingGameMode* DatingGameMode = Cast<ADatingGameMode>(GetWorld()->GetAuthGameMode());
	DatingGameMode->ButtonPressed();
}

void ADatingGameHUD::SetupDatingWidget()
{
	if (DatingSimWidgetClass)
	{
		DatingSimWidget = CreateWidget<UDatingSimWidget>(GetOwningPlayerController(), DatingSimWidgetClass);
		DatingSimWidget->AddToViewport(1);
		DatingSimWidget->OnPressedButton.AddUObject(this, &ADatingGameHUD::ButtonPressed);
	}
}
