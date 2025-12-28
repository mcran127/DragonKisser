// Copyright Brigham Young University. All Rights Reserved.


#include "RhythmGameMode.h"

#include "Components/AudioComponent.h"
#include "DragonKisserST2/GameInstance/GameInstanceBase.h"
#include "DragonKisserST2/UserInterface/MicroGameUI/MicroGameHUDs/RhythmHUD.h"

void ARhythmGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (const UGameInstanceBase* GameInstance = Cast<UGameInstanceBase>(GetGameInstance()))
	{
		if (GameInstance->SoundSystem)
		{
			GameInstance->SoundSystem->Stop();
		}
	}

	ARhythmHUD* RhythmHUD = Cast<ARhythmHUD>(PlayerController->GetHUD());
	RhythmHUD->SetupRhythmWidget();
	RhythmHUD->OpenCurtainProcess();
}
