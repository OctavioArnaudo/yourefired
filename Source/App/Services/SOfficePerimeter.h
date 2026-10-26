#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficePerimeter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficePerimeter : public UObject
{
	GENERATED_BODY()

public:
	USOfficePerimeter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficePerimeter(const FVector& TargetLocation);
};
