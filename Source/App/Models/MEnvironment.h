#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MEnvironment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMEnvironment : public UObject
{
	GENERATED_BODY()

public:
	UMEnvironment();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMEnvironment(const FVector& TargetLocation);
};
