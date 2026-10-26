#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficeGs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficeGs : public UObject
{
	GENERATED_BODY()

public:
	UCOfficeGs();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficeGs(const FVector& TargetLocation);
};
