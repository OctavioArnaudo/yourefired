#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SSmSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USSmSpawner : public UObject
{
	GENERATED_BODY()

public:
	USSmSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSSmSpawner(const FVector& TargetLocation);
};
