#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficePerimeter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficePerimeter : public UObject
{
	GENERATED_BODY()

public:
	UCOfficePerimeter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficePerimeter(const FVector& TargetLocation);
};
