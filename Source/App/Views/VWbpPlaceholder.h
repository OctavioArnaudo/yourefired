#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VWbpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVWbpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVWbpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVWbpPlaceholder(const FVector& TargetLocation);
};
