#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CCoffeePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCCoffeePickup : public UObject
{
	GENERATED_BODY()

public:
	UCCoffeePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCCoffeePickup(const FVector& TargetLocation);
};
