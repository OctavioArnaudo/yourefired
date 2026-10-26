#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VDynamicPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVDynamicPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVDynamicPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVDynamicPlaceholder(const FVector& TargetLocation);
};
