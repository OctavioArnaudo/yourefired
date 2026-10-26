#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MCoffeePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMCoffeePickup : public UObject
{
	GENERATED_BODY()

public:
	UMCoffeePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMCoffeePickup(const FVector& TargetLocation);
};
