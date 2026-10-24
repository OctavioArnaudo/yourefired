#include "EnemyBase.h"
#include "WorkerCharacter.h"
#include "Kismet/GameplayStatics.h"

AEnemyBase::AEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Health = 50.0f;
	StressDamage = 10.0f;
	AttackRange = 150.0f;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyBase::TakeDamageCustom(float DamageAmount)
{
	Health -= DamageAmount;
	if (Health <= 0.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("Enemy defeated / pacified. Destroying actor."));
		Destroy();
	}
}

void AEnemyBase::AttackPlayer()
{
	AWorkerCharacter* Player = Cast<AWorkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Player)
	{
		float Distance = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
		if (Distance <= AttackRange)
		{
			Player->AddStress(StressDamage);
			UE_LOG(LogTemp, Log, TEXT("Enemy attacked player, dealing %f stress damage."), StressDamage);
		}
	}
}
