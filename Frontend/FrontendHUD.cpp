// Copyright Brigham Young University. All Rights Reserved.


#include "FrontendHUD.h"

void AFrontendHUD::BeginPlay()
{
	Super::BeginPlay();
	if (WidgetClass)
	{
		Widget = CreateWidget<UFrontendUserWidget>(GetWorld(), WidgetClass);
		Widget->AddToViewport();

		OnWidgetBuilt.Broadcast();
	}
}

USkipCutsceneWidget* AFrontendHUD::MakeSkipCutscene()
{
	if (SkipCutsceneWidgetClass)
	{
		SkipCutsceneWidget = CreateWidget<USkipCutsceneWidget>(GetWorld(), SkipCutsceneWidgetClass);
		SkipCutsceneWidget->AddToViewport();

		return SkipCutsceneWidget;
	}
	return nullptr;
}
