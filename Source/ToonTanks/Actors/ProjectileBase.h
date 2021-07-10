// Copyright Oleg Vostokov 2021

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// COMPONENTS

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAcces = "true"))
	UParticleSystemComponent* ParticleTrail;

	// VARIABLES

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAcces = "true"))
	float MovementSpeed = 1300;

	UPROPERTY(EditAnywhere, Category = "Damage", meta = (AllowPrivateAcces = "true"))
	float Damage = 50;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAcces = "true"))
	UParticleSystem* HitParticle;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAcces = "true"))
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAcces = "true"))
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Effects", meta = (AllowPrivateAcces = "true"))
	TSubclassOf<UMatineeCameraShake> HitShake;

	// FUNCTIONS

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
			   FVector NormalImpulse, const FHitResult& Hit);

};
