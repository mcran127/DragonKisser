// Copyright Brigham Young University. All Rights Reserved.


#include "MicroGameOverlayWidget.h"

void UMicroGameOverlayWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UMicroGameOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	WinLoseObjective->SetText(MinigameDescriptionText);

	FTimerHandle TimerHandle;

	TWeakObjectPtr WeakThis(this);
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		[WeakThis]
		{
			if (!WeakThis.IsValid()) {return;}

			UMicroGameOverlayWidget* ThisWidget = Cast<UMicroGameOverlayWidget>(WeakThis.Get());
					
			ThisWidget->bStartTimer = true;
			ThisWidget->TextBorder->SetVisibility(ESlateVisibility::Hidden);
			ThisWidget->OnGameStart.Broadcast();
		},
		2.0f,
		false);
}

void UMicroGameOverlayWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (bStartTimer)
	{
		CurrentTimerValue -= InDeltaTime;
		if (CurrentTimerValue <= 0)
		{
			bStartTimer = false;
			OnGameEnd.Broadcast();
		}
	}
}

void UMicroGameOverlayWidget::TextUpdate(FText NewText)
{
	WinLoseObjective->SetText(NewText);
	TextBorder->SetVisibility(ESlateVisibility::Visible);
}
