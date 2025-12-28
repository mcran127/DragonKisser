// Copyright Brigham Young University. All Rights Reserved.


#include "MicroGameMode.h"
#include "DragonKisserST2/GameInstance/GameInstanceBase.h"
#include "DragonKisserST2/GameInstance/GameStatsSubsystem.h"
#include "Kismet/GameplayStatics.h"

AMicroGameMode::AMicroGameMode()
{
	LevelList = {
		TSoftObjectPtr<UWorld>(FSoftObjectPath(TEXT("/Game/Levels/L_DragonKisser_SidelineFight.L_DragonKisser_SidelineFight"))),
		TSoftObjectPtr<UWorld>(FSoftObjectPath(TEXT("/Game/Levels/Minigames/L_DragonKisser_DatingSim.L_DragonKisser_DatingSim"))),
		TSoftObjectPtr<UWorld>(FSoftObjectPath(TEXT("/Game/Levels/Minigames/Microgames/L_DragonKisser_DanceMicrogame.L_DragonKisser_DanceMicrogame"))),
		TSoftObjectPtr<UWorld>(FSoftObjectPath(TEXT("/Game/Levels/Minigames/Microgames/L_Ring_Microgame.L_Ring_Microgame"))),
		TSoftObjectPtr<UWorld>(FSoftObjectPath(TEXT("/Game/Levels/Minigames/Microgames/L_Clink_Microgame.L_Clink_Microgame"))),
	};
}

void AMicroGameMode::BeginPlay()
{
	UGameStatsSubsystem* GameStatsSubsystem = UGameStatsSubsystem::Get(this);
	GameStatsSubsystem->OnRizzUpdated.AddUObject(this, &AMicroGameMode::SwapMinigame);

	DragonKisserGameInstance = Cast<UGameInstanceBase>(GetGameInstance());

	PlayerController = nullptr;
	const UWorld* World = GEngine->GetWorldFromContextObject(this, EGetWorldErrorMode::LogAndReturnNull);

	if (!World)
	{
		PlayerController = nullptr;
	}

	if (const UGameInstance* GameInstance = World->GetGameInstance();
		GameInstance && GameInstance->GetWorld() == World)
	{
		int32 Index = 0;
		for (const TArray<ULocalPlayer*>& LocalPlayers = GameInstance->GetLocalPlayers();
			const ULocalPlayer* LocalPlayer : LocalPlayers)
		{
			if (APlayerController* PC = LocalPlayer->PlayerController)
			{
				if (Index == 0)
				{
					PlayerController = PC;
				}
				Index++;
			}
		}
	}

	//Possible Handle End?
}


void AMicroGameMode::MoveToMain(bool bWonGame)
{
	UGameStatsSubsystem* GameStatsSubsystem = UGameStatsSubsystem::Get(GetWorld());
	DragonKisserGameInstance->MiniGameRizz = GameStatsSubsystem->GetRizz();
	
	GameStatsSubsystem->RemoveHealth(bWonGame ? - WinHealthVal : - LoseHealthVal);
	GameStatsSubsystem->SetStun(0);
	GameStatsSubsystem->AddRizz(bWonGame ? WinVal : LoseVal);
}

void AMicroGameMode::AsyncLevelLoad(const TSoftObjectPtr<UWorld> Level)
{
	LoadPackageAsync(Level.ToString(),
		FLoadPackageAsyncDelegate::CreateLambda([=](const FName& PackageName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result)
	{
		if (Result == EAsyncLoadingResult::Succeeded)
		{
			AsyncLevelLoadFinished(Level);
		}
	}),
	0,
	PKG_ContainsMap);
}

void AMicroGameMode::SwapMinigame(int Index)
{
	switch (Index)
	{
		//commented out because rn we want to just load back into the main level
	// case 0:
	// case 2:
	// 	if (LevelList.IsValidIndex(1))
	// 	{
	// 		UGameplayStatics::OpenLevel(this, LevelList[1]->GetFName());
	// 		break;
	// 	}
	/*case 4:
		if (LevelList.IsValidIndex(2))
		{
			UGameplayStatics::OpenLevel(this, LevelList[2]->GetFName());
			break;
		}
	case 5:
	case 7:
		if (LevelList.IsValidIndex(3))
		{
			UGameplayStatics::OpenLevel(this, LevelList[3]->GetFName());
			break;
		}
	case 6:*/
	case 8:
		//if (LevelList.IsValidIndex(4))
		//{
			//UGameplayStatics::OpenLevel(this, LevelList[4]->GetFName());
			//break;
		//}
	default:
		if (LevelList.IsValidIndex(0))
		{
			UGameplayStatics::OpenLevelBySoftObjectPtr(this, LevelList[0]);
			break;
		}
	}
}

void AMicroGameMode::CheckSwapToMinigame_Implementation(int Index)
{
	UE_LOG(LogDamage, Error, TEXT("Shouldn't be here — Blueprint may not be overriding this"));
}

void AMicroGameMode::MicroGameStart() {}

void AMicroGameMode::AsyncLevelLoadFinished(TSoftObjectPtr<UWorld> Level)
{
	//const FName LevelName = FName(*FPackageName::ObjectPathToPackageName(Level.ToString()));
	//UGameplayStatics::OpenLevel(GetWorld(), LevelName, true, "");
}


