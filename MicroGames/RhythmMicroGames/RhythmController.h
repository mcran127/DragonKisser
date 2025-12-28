// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DragonKisserST2/MicroGames/MicroGameController.h"
#include "GameFramework/PlayerController.h"
#include "RhythmController.generated.h"

/**
 *@class ARhythmController
 *
 * Rhythm Game Mode Controller
 */
UCLASS()
class DRAGONKISSERST2_API ARhythmController : public AMicroGameController
{
	GENERATED_BODY()

	/**
	 * Setup Minigame Controller and binds actions
	 */
	virtual void BeginPlay() override;

	/**
	 * Calls Dance First Broadcast
	 */
	void DanceFirst();

	/**
	 * Calls Dance First End Broadcast
	 */
	void DanceFirstEnd();

	/**
	 * Calls Dance Third Broadcast
	 */
	void DanceThird();

	/**
	 * Calls Dance Third End Broadcast
	 */
	void DanceThirdEnd();

	/**
	 * Calls Dance Second Broadcast
	 */
	void DanceSecond();

	/**
	 * Calls Dance Second End Broadcast
	 */
	void DanceSecondEnd();

	/**
	 * Calls Dance Fourth Broadcast
	 */
	void DanceFourth();

	/**
	 * Calls Dance Fourth End Broadcast
	 */
	void DanceFourthEnd();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Input|Dance")
	TObjectPtr<UInputAction> Dance_First;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Dance")
	TObjectPtr<UInputAction> Dance_Second;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Dance")
	TObjectPtr<UInputAction> Dance_Third;

	UPROPERTY(EditDefaultsOnly, Category = "Input|Dance")
	TObjectPtr<UInputAction> Dance_Fourth;

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFirstPress);
	UPROPERTY()
	FOnFirstPress OnFirstPress;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnThirdPress);
	UPROPERTY()
	FOnThirdPress OnThirdPress;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSecondPress);
	UPROPERTY()
	FOnSecondPress OnSecondPress;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFourthPress);
	UPROPERTY()
	FOnFourthPress OnFourthPress;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFirstRelease);
	UPROPERTY()
	FOnFirstRelease OnFirstRelease;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnThirdRelease);
	UPROPERTY()
	FOnThirdRelease OnThirdRelease;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSecondRelease);
	UPROPERTY()
	FOnSecondRelease OnSecondRelease;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFourthRelease);
	UPROPERTY()
	FOnFourthRelease OnFourthRelease;
};
