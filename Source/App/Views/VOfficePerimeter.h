#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficePerimeter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficePerimeter : public UObject
{
	GENERATED_BODY()

public:
	UVOfficePerimeter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficePerimeter(const FVector& TargetLocation);
};
