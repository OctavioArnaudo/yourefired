#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficeCubicles.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficeCubicles : public UObject
{
	GENERATED_BODY()

public:
	UCOfficeCubicles();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficeCubicles(const FVector& TargetLocation);
};
