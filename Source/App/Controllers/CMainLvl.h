#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CMainLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCMainLvl : public UObject
{
	GENERATED_BODY()

public:
	UCMainLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCMainLvl(const FVector& TargetLocation);
};
