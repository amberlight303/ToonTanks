// Copyright Oleg Vostokov 2021


#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


APawnTurret::APawnTurret()
{

}

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive()) { return; }
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
	
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn) { return 0.0f; }
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}


