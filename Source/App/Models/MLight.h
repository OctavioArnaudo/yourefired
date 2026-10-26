#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MLight.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMLight : public UObject
{
	GENERATED_BODY()

public:
	UMLight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMLight(const FVector& TargetLocation);
};
