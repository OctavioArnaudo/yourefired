#pragma once

#include "CoreMinimal.h"
#include "App/Models/MShoot.h"
#include "App/Models/MHealth.h"

class APP_API MEnemyCharacterInstance
{
public:
	MEnemyCharacterInstance();

	float PatrolRadius;
	float AggroRange;
	float MeleeAttackRange;
	TSubclassOf<AActor> EnemyProjectileClass;
	FVector PatrolHomeLocation;
	bool bIsChasingPlayer;

	MHealth Health;

	UPROPERTY()
	UMShoot* ShootModel;

	UMShoot* GetShootModel();

	float GetHealth() const { return Health.GetHealth(); }
	float GetMaxHealth() const { return Health.GetMaxHealth(); }
	float GetHealthPercent() const { return Health.GetHealthPercent(); }
	bool IsDead() const { return Health.IsDead(); }
	float TakeDamage(float Amount) { return Health.TakeDamage(Amount); }
	float Heal(float Amount) { return Health.Heal(Amount); }
};
