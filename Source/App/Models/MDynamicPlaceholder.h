#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MDynamicPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMDynamicPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMDynamicPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMDynamicPlaceholder(const FVector& TargetLocation);
};
