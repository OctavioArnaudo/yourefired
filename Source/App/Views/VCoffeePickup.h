#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VCoffeePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVCoffeePickup : public UObject
{
	GENERATED_BODY()

public:
	UVCoffeePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVCoffeePickup(const FVector& TargetLocation);
};
