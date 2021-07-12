// Copyright Oleg Vostokov 2021

#pragma once

#include "CoreMinimal.h"
#include "ToonTanks/Pawns/PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{

	GENERATED_BODY()

public:

	// Sets default values for this pawn's properties
	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void HandleDestruction() override;

	bool GetIsPlayerAlive();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 100.f;

	APlayerController* PlayerControllerRef;

	bool bIsPlayerAlive = true;

	FVector MoveDirection;

	FQuat RotationDirection;

	void CalculateMoveInput(float Value);

	void CalculateRotateInput(float Value);

	void Move();

	void Rotate();

};
