#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CUaReloader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCUaReloader : public UObject
{
	GENERATED_BODY()

public:
	UCUaReloader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCUaReloader(const FVector& TargetLocation);
};
