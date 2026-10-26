#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CUaLoader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCUaLoader : public UObject
{
	GENERATED_BODY()

public:
	UCUaLoader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCUaLoader(const FVector& TargetLocation);
};
