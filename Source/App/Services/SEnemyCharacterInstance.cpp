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
	UE_LOG(LogTemp, Verbose, TEXT("[SEnemyCharacterInstance] Delegating patrol execution to SPatrol unit service..."));
	USPatrol* PatrolService = NewObject<USPatrol>();
	if (PatrolService)
	{
		PatrolService->ExecutePatrolStep(EnemyCharacter, Model.PatrolHomeLocation, Model.PatrolRadius);
	}
}

void SEnemyCharacterInstance::ExecuteChaseAndAttack(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model)
{
	if (!EnemyCharacter || !EnemyCharacter->GetWorld()) return;
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
		USMelee* MeleeService = NewObject<USMelee>();
		if (MeleeService)
		{
			MeleeService->PerformMeleeAttack(EnemyCharacter);
		}
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

	USShoot* ShootService = NewObject<USShoot>();
	if (ShootService && Model.ShootModel)
	{
		// Use discrete rate-limited shoot service so enemy fires discrete 1-by-1 shots instead of continuous stream
		float CurrentTime = EnemyCharacter->GetWorld()->GetTimeSeconds();
		ShootService->PerformDiscreteRangedShoot(EnemyCharacter, Model.ShootModel, Model.EnemyProjectileClass, CurrentTime);
	}
}
