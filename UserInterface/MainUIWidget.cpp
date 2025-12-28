// Copyright Brigham Young University. All Rights Reserved.


#include "MainUIWidget.h"

#include "DragonKisserST2/GameInstance/GameStatsSubsystem.h"

void UMainUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UGameStatsSubsystem::Get(this)->OnRizzUpdated.AddUObject(this, &ThisClass::RizzUpdated);
}

void UMainUIWidget::UpdateHealth_Implementation()
{
}

void UMainUIWidget::RizzUpdated_Implementation(int Ignored)
{
}
