#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWorldLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCWorldLvl : public UObject
{
	GENERATED_BODY()

public:
	UCWorldLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCWorldLvl(const FVector& TargetLocation);
};
