// Copyright Brigham Young University. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PaperSpriteComponent.h"
#include "RingPlayer.generated.h"

UCLASS()
class DRAGONKISSERST2_API ARingPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ARingPlayer();

	UPROPERTY(EditAnywhere, Category = "Mesh");
	TObjectPtr<UPaperSpriteComponent> CharacterHandPlane;

	UPROPERTY(EditAnywhere, Category = "Mesh");
	TObjectPtr<UPaperSpriteComponent> RingPlaneFront;

	UPROPERTY(EditAnywhere, Category = "Mesh");
	TObjectPtr<UPaperSpriteComponent> RingPlaneBack;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void SetRotation(FRotator ToRotate);

	UFUNCTION()
	void MovePlayer(const FInputActionValue& Value);
};
