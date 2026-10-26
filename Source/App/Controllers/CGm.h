#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCGm : public UObject
{
	GENERATED_BODY()

public:
	UCGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCGm(const FVector& TargetLocation);
};
