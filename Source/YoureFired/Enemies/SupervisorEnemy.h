#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "SupervisorEnemy.generated.h"

/**
 * Supervisor Enemy - Patrols floor, attacks with judging stares and performance reviews.
 */
UCLASS()
class YOUREFIRED_API ASupervisorEnemy : public AEnemyBase
{
	GENERATED_BODY()

public:
	ASupervisorEnemy();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Supervisor Stats")
	float JudgingStareDamage;

	UFUNCTION(BlueprintCallable, Category = "Supervisor Actions")
	void PerformJudgingStare();
};
