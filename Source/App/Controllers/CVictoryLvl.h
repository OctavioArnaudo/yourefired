#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CVictoryLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCVictoryLvl : public UObject
{
	GENERATED_BODY()

public:
	UCVictoryLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCVictoryLvl(const FVector& TargetLocation);
};
