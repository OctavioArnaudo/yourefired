#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MBpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMBpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMBpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMBpPlaceholder(const FVector& TargetLocation);
};
