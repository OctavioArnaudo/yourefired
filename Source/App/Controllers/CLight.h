#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CLight.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCLight : public UObject
{
	GENERATED_BODY()

public:
	UCLight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCLight(const FVector& TargetLocation);
};
