#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MSmPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMSmPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMSmPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMSmPlaceholder(const FVector& TargetLocation);
};
