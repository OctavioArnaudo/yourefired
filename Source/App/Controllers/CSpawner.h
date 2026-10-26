#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCSpawner : public UObject
{
	GENERATED_BODY()

public:
	UCSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCSpawner(const FVector& TargetLocation);
};
