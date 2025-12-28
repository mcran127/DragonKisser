// Copyright Brigham Young University. All Rights Reserved.


#include "DatingSimButton.h"

void UDatingSimButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	TextBox->SetText(ButtonText);
}

void UDatingSimButton::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &ThisClass::OnButtonPressed);
	Button->OnHovered.AddDynamic(this, &ThisClass::OnButtonFocus);
	Button->OnUnhovered.AddDynamic(this, &ThisClass::OnButtonUnfocus);
}

void UDatingSimButton::OnButtonPressed()
{
	OnPressed.Broadcast(bIsCorrect, ResponseText);
}

void UDatingSimButton::OnButtonFocus()
{
	Button->SetBackgroundColor(FLinearColor(.244, .714, 1, 1));
}

void UDatingSimButton::NativeOnAddedToFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnAddedToFocusPath(InFocusEvent);
	OnButtonFocus();
}

void UDatingSimButton::OnButtonUnfocus()
{
	Button->SetBackgroundColor(FLinearColor(.494, .494, .494, 1));
}

void UDatingSimButton::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnRemovedFromFocusPath(InFocusEvent);
	OnButtonUnfocus();
}
