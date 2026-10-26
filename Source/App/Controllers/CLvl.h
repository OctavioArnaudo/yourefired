#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCLvl : public UObject
{
	GENERATED_BODY()

public:
	UCLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCLvl(const FVector& TargetLocation);
};
