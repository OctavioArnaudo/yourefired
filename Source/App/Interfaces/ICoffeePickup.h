#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ICoffeePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UICoffeePickup : public UObject
{
	GENERATED_BODY()

public:
	UICoffeePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessICoffeePickup(const FVector& TargetLocation);
};
