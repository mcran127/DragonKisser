// Copyright Brigham Young University. All Rights Reserved.


#include "DatingSimWidget.h"

#include "Algo/RandomShuffle.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/MicroGameHUD.h"
#include "DragonKisserST2/MicroGames/MicroGameMode.h"

bool UDatingSimWidget::CheckDatingThreshold(int32 Threshold)
{
	return DragonKisserGameInstance->bThresholdsReached[Threshold];
}

void UDatingSimWidget::OnButtonPressed(bool bIsCorrect, FText Response)
{
	OnPressedButton.Broadcast();
	DisableButtons();
	
	DragonTextBox->SetText(Response);
	bSuccess = bIsCorrect;

	FTimerHandle TimerHandle;
	TWeakObjectPtr WeakThis(this);
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		[WeakThis]
		{
			if (!WeakThis.IsValid()) {return;}

			const UDatingSimWidget* ThisWidget = Cast<UDatingSimWidget>(WeakThis.Get());
			AMicroGameHUD* MicroGameHUD = Cast<AMicroGameHUD>(ThisWidget->GetOwningPlayer()->GetHUD());
			
			MicroGameHUD->CloseCurtainProcess();
		},
		1.5f,
		false);
}

void UDatingSimWidget::NativeConstruct()
{
	Super::NativeConstruct();

	DragonKisserGameInstance = Cast<UGameInstanceBase>(GetGameInstance());
	
	if (CheckDatingThreshold(5) && QuestionAnswerSet.IsValidIndex(2))
	{
		SetupQuestions(QuestionAnswerSet[2]);
		return;
	}

	if (CheckDatingThreshold(2) && QuestionAnswerSet.IsValidIndex(1))
	{
		SetupQuestions(QuestionAnswerSet[1]);
		return;
	}
	
	if (QuestionAnswerSet.IsValidIndex(0))
	{
		SetupQuestions(QuestionAnswerSet[0]);
	}
}

void UDatingSimWidget::DisableButtons()
{
	for (int i = 0; i < AllButtons.Num(); i++)
	{
		AllButtons[i]->SetIsEnabled(false);
	}
}

void UDatingSimWidget::SetupQuestions(UQuestionAnswerDataAsset* QuestionList)
{
	Algo::RandomShuffle(QuestionList->QuestionAnswersArray);
	Algo::RandomShuffle(QuestionList->QuestionAnswersArray[0].Answers);

	auto [Question, Answers] = QuestionList->QuestionAnswersArray[0];
	
	DragonTextBox->SetText(FText::FromString(Question));

	for (FCorrectAnswers CorrectAnswers : Answers)
	{
		if (ButtonClass)
		{
			UDatingSimButton* CurrButton = CreateWidget<UDatingSimButton>(this->GetOwningPlayer(), ButtonClass);

			CurrButton->ButtonText = FText::FromString(CorrectAnswers.Answer);
			CurrButton->bIsCorrect = CorrectAnswers.bIsCorrect;
			CurrButton->ResponseText = FText::FromString(CorrectAnswers.LucianaResponse);

			AllButtons.Add(CurrButton);

			AnswerBox->AddChild(CurrButton);

			CurrButton->OnPressed.AddUObject(this, &UDatingSimWidget::OnButtonPressed);
		}
	}
	AllButtons[0]->SetFocus();
}
