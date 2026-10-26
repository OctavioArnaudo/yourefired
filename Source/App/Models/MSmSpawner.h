#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MSmSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMSmSpawner : public UObject
{
	GENERATED_BODY()

public:
	UMSmSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMSmSpawner(const FVector& TargetLocation);
};
