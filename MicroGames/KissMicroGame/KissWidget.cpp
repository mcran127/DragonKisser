// Copyright Brigham Young University. All Rights Reserved.


#include "KissWidget.h"

#include "Components/AudioComponent.h"
#include "Components/Button.h"
#include "DragonKisserST2/GameInstance/GameInstanceBase.h"
#include "DragonKisserST2/UserInterface/EndGameWidget.h"
#include "Kismet/GameplayStatics.h"

void UKissWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlaySliderAnimation();

	if (GetOwningPlayer())
	{
		GetOwningPlayer()->bShowMouseCursor = true;
		SetUserFocus(GetOwningPlayer());
	}

	if (KissButton)
	{
		KissButton->OnPressed.AddDynamic(this, &UKissWidget::OnButtonPushed);
	}
}

void UKissWidget::PlaySliderAnimation()
{
	if (SliderAnimation)
	{
		PlayAnimation(
			SliderAnimation,
			0,
			0,
			EUMGSequencePlayMode::PingPong);
	}
}

void UKissWidget::OnButtonPushed()
{
	bCanPress = false;
	float CurrTime = 0;

	if (SliderAnimation && IsAnimationPlaying(SliderAnimation))
	{
		CurrTime = GetAnimationCurrentTime(SliderAnimation);
		StopAnimation(SliderAnimation);
	}
	
	FinalWidget = Cast<UEndGameWidget>(CreateWidget(this, FinalWidgetClass));

	if (FinalWidget)
	{
		FinalWidget->WinLoseVal = CurrTime <= .4 || CurrTime >= .6;
		FinalWidget->SetImage();
		FinalWidget->AddToViewport();
	}

	if (const UGameInstanceBase* GameInstanceBase = Cast<UGameInstanceBase>(GetGameInstance()))
	{
		GameInstanceBase->SoundSystem->Stop();
	}

	if (WinJingle)
	{
		PlaySound(WinJingle);
	}

	FTimerHandle TimerHandle;
	TWeakObjectPtr WeakThis(this);
	GetWorld()->GetTimerManager().SetTimer(
	TimerHandle,
	[WeakThis]
	{
		if (!WeakThis.IsValid()) {return;}

		const UKissWidget* KissWidget = Cast<UKissWidget>(WeakThis.Get());
		
		UGameplayStatics::OpenLevelBySoftObjectPtr(
			KissWidget->GetWorld(),
			KissWidget->FrontendLevelReference
			);
	},
	10.0f,
	false);
	
}
