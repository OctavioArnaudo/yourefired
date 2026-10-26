#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSmSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCSmSpawner : public UObject
{
	GENERATED_BODY()

public:
	UCSmSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCSmSpawner(const FVector& TargetLocation);
};
