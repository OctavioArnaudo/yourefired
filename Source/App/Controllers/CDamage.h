#pragma once

#include "CoreMinimal.h"
#include "CDamage.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCDamage : public UObject
{
	GENERATED_BODY()

public:
	UCDamage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	float ProcessDamageCalculation(float BaseDamage, float CritMultiplier, float RawDamage);
};
