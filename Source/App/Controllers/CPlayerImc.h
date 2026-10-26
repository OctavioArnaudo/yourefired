#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerImc.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerImc : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerImc();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerImc(const FVector& TargetLocation);
};
