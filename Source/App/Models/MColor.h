#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MColor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMColor : public UObject
{
	GENERATED_BODY()

public:
	UMColor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMColor(const FVector& TargetLocation);
};
