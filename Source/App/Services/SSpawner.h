#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USSpawner : public UObject
{
	GENERATED_BODY()

public:
	USSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSSpawner(const FVector& TargetLocation);
};
