#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficePerimeter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficePerimeter : public UObject
{
	GENERATED_BODY()

public:
	UMOfficePerimeter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficePerimeter(const FVector& TargetLocation);
};
