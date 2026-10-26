#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficeGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficeGm : public UObject
{
	GENERATED_BODY()

public:
	UCOfficeGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficeGm(const FVector& TargetLocation);
};
