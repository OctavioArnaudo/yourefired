#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CDynamicPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCDynamicPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCDynamicPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCDynamicPlaceholder(const FVector& TargetLocation);
};
