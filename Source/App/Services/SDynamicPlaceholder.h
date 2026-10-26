#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDynamicPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USDynamicPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USDynamicPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSDynamicPlaceholder(const FVector& TargetLocation);
};
