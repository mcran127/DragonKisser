// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "MinigameItem.generated.h"


class USplineComponent;
class UItemMovementComponent;
class UStaticMeshComponent;
class UCapsuleComponent;
class USpotLightComponent;
/**
 * @class AMinigameItem
 *
 * Item to spawn during gameplay as a way to transition to minigames
 */
UCLASS()
class DRAGONKISSERST2_API AMinigameItem : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Setup Item Components (Mesh, Collision Capsule, and Light)
	 */
	AMinigameItem();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	TObjectPtr<UStaticMeshComponent> CurrentMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	TArray<TObjectPtr<UStaticMesh>> MeshList;

	UPROPERTY(EditAnywhere, Category="Capsule")
	TObjectPtr<UCapsuleComponent> InteractCapsule;

	UPROPERTY(EditAnywhere, Category="Light")
	TObjectPtr<USpotLightComponent> LightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<USplineComponent> SplineRef;

	/**
	 * Sets up value to be used in map swap and mesh
	 * 
	 * @param SetupNum Value passed in from the blueprint to be used for the MeshList index and MiniGameNumber
	 */
	UFUNCTION(BlueprintCallable, Category="MeshSwap")
	void SetupMiniGame(int32 SetupNum);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOverlapped);

	UPROPERTY(BlueprintAssignable)
	FOnOverlapped OnOverlapped;

	bool bCanInteract = false;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void LaunchAlongSpline(USplineComponent* Spline);

protected:
	
	/**
	 * Sets up first mesh to be ovverrode in SetupMiniGame and binds logic to begin and end overlap
	 */
	virtual void BeginPlay() override;

	/**
	 * Sets the item to be interactable if the overlapping actor is Domingo and creates a notification for the player
	 * 
	 * @param OverlappedComp Overrode from Begin Overlap, Unused
	 * @param OtherActor Overlapping actor, checks if is Domingo
	 * @param OtherComp Overrode from Begin Overlap, Unused
	 * @param OtherBodyIndex Overrode from Begin Overlap, Unused
	 * @param bFromSweep Overrode from Begin Overlap, Unused
	 * @param SweepResult Overrode from Begin Overlap, Unused
	 */
	UFUNCTION()
	void OnPickup(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	/**
	 * Sets the item to be interactable if Domingo left the space and removes notification
	 * 
	 * @param OverlappedComp Overrode from End Overlap, Unused
	 * @param OtherActor Previously overlapped actor, checks if Domingo
	 * @param OtherComp Overrode from End Overlap, Unused
	 * @param OtherBodyIndex Overrode from End Overlap, Unused
	 */
	UFUNCTION()
	void PlayerExit(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
	
	int32 MiniGameNumber = 0;

	/**
	 * When the player interacts with the item, tells the game mode to swap level and destroys this item
	 */
	UFUNCTION(BlueprintCallable, Category="Interact")
	void PlayerInteract();


private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	float Speed = 0.5f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	float SplineProgress = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	bool bMoving = false;
	
};
