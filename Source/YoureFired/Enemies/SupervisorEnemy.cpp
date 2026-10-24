#include "SupervisorEnemy.h"
#include "WorkerCharacter.h"
#include "Kismet/GameplayStatics.h"

ASupervisorEnemy::ASupervisorEnemy()
{
	Health = 80.0f;
	StressDamage = 15.0f;
	JudgingStareDamage = 20.0f;
	AttackRange = 300.0f;
}

void ASupervisorEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ASupervisorEnemy::PerformJudgingStare()
{
	AWorkerCharacter* Player = Cast<AWorkerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Player)
	{
		Player->AddStress(JudgingStareDamage);
		UE_LOG(LogTemp, Warning, TEXT("Supervisor catches player 'doing nothing' and delivers a Judging Stare! Stress +%f"), JudgingStareDamage);
	}
}
