#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficeActors.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficeActors : public UObject
{
	GENERATED_BODY()

public:
	UCOfficeActors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficeActors(const FVector& TargetLocation);
};
