// Fill out your copyright notice in the Description page of Project Settings.


#include "DragonKisserST2GameModeBase.h"

#include "DragonKisserST2/GameInstance/GameMusicSubsystem.h"
#include "DragonKisserST2/GameInstance/GameStatsSubsystem.h"
#include "DragonKisserST2/MicroGames/MiniGame/MinigameItem.h"
#include "DragonKisserST2/MicroGames/MiniGame/MiniGameLocator.h" // needs to be here
#include "DragonKisserST2/MicroGames/MiniGame/MiniGameSpawnLocator.h" // needs to be here
#include "Kismet/GameplayStatics.h"


void ADragonKisserST2GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UGameStatsSubsystem* const GameStats = UGameStatsSubsystem::Get(this);
	GameStats->OnRizzUpdated.AddUObject(this, &ADragonKisserST2GameModeBase::CheckSwapToMinigame);
	GameStats->OnStunEmptied.AddDynamic(this, &ADragonKisserST2GameModeBase::SetSpotlightFinished);

	UGameplayStatics::GetAllActorsOfClass(this, MiniGameLocatorClass, MiniGameLocations);
	MiniGameSpawnLocation = Cast<AMiniGameSpawnLocator>(UGameplayStatics::GetActorOfClass(this, MiniGameSpawnLocationClass));

	UGameMusicSubsystem::Get(this)->StartMetronome();
}

void ADragonKisserST2GameModeBase::SpawnMinigameItem(int SetupIndex, TSubclassOf<AMinigameItem> ItemClass)
{
	if (bMiniGameItemExists) { return; }
	if (MiniGameSpawnLocation == nullptr) { return; }
	if (ItemClass == nullptr) { return; }
	bMiniGameItemExists = true;
	
	// AMinigameItem* MinigameItem = Cast<AMinigameItem>(GetWorld()->SpawnActor(ItemClass, &MiniGameSpawnLocation->GetTransform()));
	AMinigameItem* MinigameItem = GetWorld()->SpawnActor<AMinigameItem>(ItemClass, MiniGameSpawnLocation->GetTransform());
	MinigameItem->OnOverlapped.AddDynamic(this, &ThisClass::SetNoMiniGameExists);
	MinigameItem->SetupMiniGame(SetupIndex);
	MinigameItem->LaunchAlongSpline(MiniGameSpawnLocation->MakeLaunchArc(MiniGameLocations[FMath::RandRange(0, MiniGameLocations.Num() - 1)]));
}

void ADragonKisserST2GameModeBase::StartCpr_Implementation()
{
	OnStartCpr.Broadcast();
}

void ADragonKisserST2GameModeBase::SucceedCpr_Implementation()
{
	OnSucceedCpr.Broadcast();
}

void ADragonKisserST2GameModeBase::FailCpr_Implementation()
{
	OnFailCpr.Broadcast();
}

void ADragonKisserST2GameModeBase::SpawnSpotlight_Implementation()
{
}

void ADragonKisserST2GameModeBase::SetSpotlightFinished_Implementation()
{
}


void ADragonKisserST2GameModeBase::SwapToNewLevel_Implementation(int ToSwap)
{
}



