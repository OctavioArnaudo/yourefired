#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficePatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficePatrol : public UObject
{
	GENERATED_BODY()

public:
	UCOfficePatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficePatrol(const FVector& TargetLocation);
};
