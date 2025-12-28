// Copyright Brigham Young University. All Rights Reserved.


#include "ComboDisplayWidget.h"

void UComboDisplayWidget::UpdateRating(const FString Text) const
{
	if (RatingText)
	{
		RatingText->SetVisibility(ESlateVisibility::Visible);
		RatingText->SetText(FText::FromString(Text));
	}
}

void UComboDisplayWidget::UpdateFinal(const FString Text) const
{
	if (RatingText)
	{
		RatingText->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (ComboText)
	{
		ComboText->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (FinalText)
	{
		FinalText->SetVisibility(ESlateVisibility::Visible);
		FinalText->SetText(FText::FromString(Text));
	}
}
