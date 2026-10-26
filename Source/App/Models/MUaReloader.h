#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MUaReloader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMUaReloader : public UObject
{
	GENERATED_BODY()

public:
	UMUaReloader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMUaReloader(const FVector& TargetLocation);
};
