#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSettingsLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCSettingsLvl : public UObject
{
	GENERATED_BODY()

public:
	UCSettingsLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCSettingsLvl(const FVector& TargetLocation);
};
