#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

/**
 * Base class for all office enemies (Coworkers, Supervisors, HR agents).
 */
UCLASS()
class YOUREFIRED_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/** Enemy Health / Distraction threshold */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float Health;

	/** Stress damage dealt to player when attacking */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float StressDamage;

	/** Attack range */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float AttackRange;

	/** Take damage / distraction */
	UFUNCTION(BlueprintCallable, Category = "Enemy Actions")
	virtual void TakeDamageCustom(float DamageAmount);

	/** Attack player */
	UFUNCTION(BlueprintCallable, Category = "Enemy Actions")
	virtual void AttackPlayer();
};
