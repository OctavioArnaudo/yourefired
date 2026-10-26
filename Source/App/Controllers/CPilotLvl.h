#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPilotLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPilotLvl : public UObject
{
	GENERATED_BODY()

public:
	UCPilotLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPilotLvl(const FVector& TargetLocation);
};
