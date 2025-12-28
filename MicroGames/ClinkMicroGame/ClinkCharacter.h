// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "ClinkCharacter.generated.h"

/**
 * @class AClinkCharacter
 *
 * Main Character for the Clink MicroGame
 */
UCLASS()
class DRAGONKISSERST2_API AClinkCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/**
	 * Sets up Domingo Character clink image plane
	 */
	AClinkCharacter();

protected:
	/**
	 * Calls super
	 */
	virtual void BeginPlay() override;

public:
	/**
	 * Calls super
	 * 
	 * @param PlayerInputComponent Player Input component
	 */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> GlassPlane;

	/**
	 * Moves character in 2D space based on controller input
	 * 
	 * @param Value 2D vector controller input
	 */
	UFUNCTION(BlueprintCallable, Category = "MicroGames")
	void MoveCharacter(const FInputActionValue& Value);
};
