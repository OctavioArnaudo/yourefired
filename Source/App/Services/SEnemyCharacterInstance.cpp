#include "SEnemyCharacterInstance.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "App/Models/MEnemyCharacterInstance.h"
#include "App/Controllers/CProjectile.h"

SEnemyCharacterInstance::SEnemyCharacterInstance() {}

void SEnemyCharacterInstance::UpdateAIBehavior(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	if (!EnemyCharacter) return;

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(EnemyCharacter, 0);
	if (!PlayerPawn) return;

	float DistanceToPlayer = FVector::Dist(EnemyCharacter->GetActorLocation(), PlayerPawn->GetActorLocation());

	if (DistanceToPlayer <= Model.AggroRange)
	{
		Model.bIsChasingPlayer = true;
		ExecuteChaseAndAttack(EnemyCharacter, Model);
	}
	else
	{
		Model.bIsChasingPlayer = false;
		ExecutePatrol(EnemyCharacter, Model);
	}
}

void SEnemyCharacterInstance::ExecutePatrol(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	UE_LOG(LogTemp, Verbose, TEXT("[SEnemyCharacterInstance] Patrolling..."));
}

void SEnemyCharacterInstance::ExecuteChaseAndAttack(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	if (!EnemyCharacter) return;
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(EnemyCharacter, 0);
	if (!PlayerPawn) return;

	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	float DistanceToPlayer = FVector::Dist(EnemyCharacter->GetActorLocation(), PlayerLocation);

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(EnemyCharacter->GetActorLocation(), PlayerLocation);
	EnemyCharacter->SetActorRotation(FRotator(0.0f, LookAtRotation.Yaw, 0.0f));

	EnemyCharacter->AddMovementInput((PlayerLocation - EnemyCharacter->GetActorLocation()).GetSafeNormal(), 1.0f);

	if (DistanceToPlayer <= Model.MeleeAttackRange)
	{
		PerformMeleeAttack();
	}
	else
	{
		PerformRangedAttack(EnemyCharacter, Model);
	}
}

void SEnemyCharacterInstance::PerformMeleeAttack()
{
	UE_LOG(LogTemp, Log, TEXT("[SEnemyCharacterInstance] Enemy MELEE attack executed!"));
}

void SEnemyCharacterInstance::PerformRangedAttack(ACharacter* EnemyCharacter, const MEnemyCharacterInstance& Model)
{
	if (!EnemyCharacter || !EnemyCharacter->GetWorld()) return;

	TSubclassOf<AActor> ClassToSpawn = Model.EnemyProjectileClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = ACProjectile::StaticClass();
	}

	FVector SpawnLocation = EnemyCharacter->GetActorLocation() + (EnemyCharacter->GetActorForwardVector() * 100.0f);
	FRotator SpawnRotation = EnemyCharacter->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = EnemyCharacter;
	SpawnParams.Instigator = EnemyCharacter;

	EnemyCharacter->GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	UE_LOG(LogTemp, Log, TEXT("[SEnemyCharacterInstance] Enemy RANGED attack projectile spawned!"));
}
