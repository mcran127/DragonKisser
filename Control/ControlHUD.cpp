// Copyright Brigham Young University. All Rights Reserved.


#include "ControlHUD.h"



AControlHUD::AControlHUD()
{
}

void AControlHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MainUI)
	{
		MainWidget = CreateWidget<UMainUIWidget>(GetOwningPlayerController(), MainUI);
		MainWidget->AddToPlayerScreen();
	}
	
	if (PlayerNotificationUI)
	{
		PlayerNotificationWidget = CreateWidget<UPlayerPromptWidget>(GetOwningPlayerController(), PlayerNotificationUI);
		
		PlayerNotificationWidget->AddToPlayerScreen();
	}
	
}

void AControlHUD::StartCpr()
{
	if (CprUI)
	{
		CprWidget = CreateWidget<UCprWidget>(GetOwningPlayerController(), CprUI);
		CprWidget->AddToPlayerScreen();
	}
}

void AControlHUD::EndCpr()
{
	if (CprWidget)
	{
		CprWidget->RemoveFromParent();
	}
	if (MainWidget)
	{
		MainWidget->UpdateHealth();
	}
}

void AControlHUD::CprInput() const
{
	if (CprWidget)
	{
		CprWidget->CprAction();
	}
}
