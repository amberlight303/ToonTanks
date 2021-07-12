// Copyright Oleg Vostokov 2021

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;
class AProjectileBase;
class UHealthComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{

	GENERATED_BODY()

public:	

	// Sets default values for this pawn's properties
	APawnBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void HandleDestruction();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RotateTurret(FVector LookAtTarget);

	void Fire();

private:

	// COMPONENTS

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere,Category = "Components", meta = (AllowPrivateAcces = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	USceneComponent* ProjectileSpawnPoint;
	
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UHealthComponent* HealthComponent;

	// VARIABLES

	UPROPERTY(EditAnywhere, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectileBase> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* DeathParticle;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAcces = "true"))
	USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAcces = "true"))
	TSubclassOf<UMatineeCameraShake> DeathShake;

};
