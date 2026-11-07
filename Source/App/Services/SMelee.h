#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SMelee.generated.h"

class ACharacter;

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

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSMelee(const FVector& TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool PerformMeleeAttack(ACharacter* Attacker);
};
