#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SEnemyCharacterInstance.generated.h"

class ACharacter;
class MEnemyCharacterInstance;
class USPatrol;
class USMelee;
class USShoot;

UCLASS(BlueprintType, Blueprintable)
class APP_API USEnemyCharacterInstance : public UObject
{
	GENERATED_BODY()

public:
	USEnemyCharacterInstance();

	void UpdateAIBehavior(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model);
	void ExecutePatrol(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model);
	void ExecuteChaseAndAttack(ACharacter* EnemyCharacter, MEnemyCharacterInstance& Model);
	void PerformMeleeAttack();
	void PerformRangedAttack(ACharacter* EnemyCharacter, const MEnemyCharacterInstance& Model);

	UPROPERTY()
	USPatrol* PatrolService;

	UPROPERTY()
	USMelee* MeleeService;

	UPROPERTY()
	USShoot* ShootService;

	float LastFireTime;
	float FireRate;
};

// Typedef alias so any existing references to SEnemyCharacterInstance work seamlessly
typedef USEnemyCharacterInstance SEnemyCharacterInstance;
