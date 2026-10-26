#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CEnvironment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCEnvironment : public UObject
{
	GENERATED_BODY()

public:
	UCEnvironment();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCEnvironment(const FVector& TargetLocation);
};
