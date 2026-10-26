#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SSettingsLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USSettingsLvl : public UObject
{
	GENERATED_BODY()

public:
	USSettingsLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSSettingsLvl(const FVector& TargetLocation);
};
