#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SCoffeePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USCoffeePickup : public UObject
{
	GENERATED_BODY()

public:
	USCoffeePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSCoffeePickup(const FVector& TargetLocation);
};
