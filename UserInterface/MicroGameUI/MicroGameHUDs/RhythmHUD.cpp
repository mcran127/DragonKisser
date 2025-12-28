// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmHUD.h"

void ARhythmHUD::SetupRhythmWidget()
{
	if (RhythmWidgetClass)
	{
		RhythmWidget = CreateWidget<URhythmWidget>(GetOwningPlayerController(), RhythmWidgetClass);
		if (RhythmWidget)
		{
			RhythmWidget->AddToViewport();

			ComboDisplayWidget = RhythmWidget->ComboDisplayWidget;
		}
	}
}

void ARhythmHUD::UpdateComboDisplayFinal(const FString& ToUpdate) const
{
	ComboDisplayWidget->UpdateFinal(ToUpdate);
}

void ARhythmHUD::UpdateCombo(const FString& ComboRating, const bool IncrementCombo) const
{
	if (IncrementCombo)
	{
		ComboDisplayWidget->Combo++;
	}
	else
	{
		ComboDisplayWidget->Combo = 0;
	}
	
	ComboDisplayWidget->UpdateRating(ComboRating);
}
