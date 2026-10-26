#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficeItems.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficeItems : public UObject
{
	GENERATED_BODY()

public:
	UCOfficeItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficeItems(const FVector& TargetLocation);
};
