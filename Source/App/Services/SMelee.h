#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SMelee.generated.h"

class ACharacter;
class AActor;
class AController;

UCLASS(BlueprintType, Blueprintable)
class APP_API USMelee : public UObject
{
	GENERATED_BODY()

public:
	USMelee();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float MeleeDamage;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSMelee(const FVector& TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool PerformMeleeAttack(ACharacter* Attacker);

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool PerformMeleeAttackOnTarget(ACharacter* Attacker, AActor* Target);

	static void ApplyDamageUniversal(AActor* Target, float DamageAmount, AController* EventInstigator, AActor* DamageCauser);
};
