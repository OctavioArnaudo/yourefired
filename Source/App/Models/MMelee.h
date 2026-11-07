#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MMelee.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMMelee : public UObject
{
	GENERATED_BODY()

public:
	UMMelee();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	float MeleeDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	float MeleeRange;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMMelee(const FVector& TargetLocation);
};
