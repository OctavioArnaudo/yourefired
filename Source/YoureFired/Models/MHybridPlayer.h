#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HybridPlayerModel.generated.h"

/**
 * Model for Hybrid Player (Combines melee, range, and inventory states)
 */
UCLASS()
class YOUREFIRED_API AHybridPlayerModel : public ACharacter
{
	GENERATED_BODY()

public:
	AHybridPlayerModel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Stats")
	float StressLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Stats")
	float MaxStress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Stats")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player | Stats")
	float RunSpeed;
};
