#include "SEnemyCharacterInstance.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "App/Models/MEnemyCharacterInstance.h"
#include "App/Controllers/CProjectile.h"
#include "App/Services/SPatrol.h"
#include "App/Services/SMelee.h"
#include "App/Services/SShoot.h"

USEnemyCharacterInstance::USEnemyCharacterInstance()
	: PatrolService(nullptr)
	, MeleeService(nullptr)
	, ShootService(nullptr)
	, LastFireTime(0.0f)
	, FireRate(1.5f)
{
}

void USEnemyCharacterInstance::UpdateAIBehavior(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	if (!IsValid(EnemyCharacter)) return;

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(EnemyCharacter, 0);
	if (!IsValid(PlayerPawn)) return;

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

void USEnemyCharacterInstance::ExecutePatrol(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	if (!PatrolService)
	{
		PatrolService = NewObject<USPatrol>(this);
	}

	if (IsValid(PatrolService))
	{
		PatrolService->ExecutePatrolStep(EnemyCharacter, Model.PatrolHomeLocation, Model.PatrolRadius);
	}
}

void USEnemyCharacterInstance::ExecuteChaseAndAttack(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	if (!IsValid(EnemyCharacter) || !EnemyCharacter->GetWorld()) return;
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(EnemyCharacter, 0);
	if (!IsValid(PlayerPawn)) return;

	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	float DistanceToPlayer = FVector::Dist(EnemyCharacter->GetActorLocation(), PlayerLocation);

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(EnemyCharacter->GetActorLocation(), PlayerLocation);
	EnemyCharacter->SetActorRotation(FRotator(0.0f, LookAtRotation.Yaw, 0.0f));

	EnemyCharacter->AddMovementInput((PlayerLocation - EnemyCharacter->GetActorLocation()).GetSafeNormal(), 1.0f);

	if (DistanceToPlayer <= Model.MeleeAttackRange)
	{
		PerformMeleeAttack();
		if (!MeleeService)
		{
			MeleeService = NewObject<USMelee>(this);
		}
		if (IsValid(MeleeService))
		{
			MeleeService->PerformMeleeAttack(EnemyCharacter);
		}
	}
	else
	{
		PerformRangedAttack(EnemyCharacter, Model);
	}
}

void USEnemyCharacterInstance::PerformMeleeAttack()
{
	UE_LOG(LogTemp, Log, TEXT("[SEnemyCharacterInstance] Enemy MELEE attack executed!"));
}

void USEnemyCharacterInstance::PerformRangedAttack(ACharacter* EnemyCharacter, const MEnemyCharacterInstance& Model)
{
	if (!IsValid(EnemyCharacter) || !EnemyCharacter->GetWorld()) return;

	float CurrentTime = EnemyCharacter->GetWorld()->GetTimeSeconds();
	if ((CurrentTime - LastFireTime) < FireRate)
	{
		return;
	}

	LastFireTime = CurrentTime;

	if (!ShootService)
	{
		ShootService = NewObject<USShoot>(this);
	}

	if (IsValid(ShootService))
	{
		TSubclassOf<AActor> ProjClass = Model.EnemyProjectileClass;
		ShootService->PerformRangedShoot(EnemyCharacter, ProjClass);
		UE_LOG(LogTemp, Log, TEXT("[SEnemyCharacterInstance] Enemy fired discrete projectile at t=%.2fs"), CurrentTime);
	}
}
