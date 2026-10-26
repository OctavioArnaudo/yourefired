#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CDefeatLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCDefeatLvl : public UObject
{
	GENERATED_BODY()

public:
	UCDefeatLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCDefeatLvl(const FVector& TargetLocation);
};
