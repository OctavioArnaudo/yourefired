#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MSettingsLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMSettingsLvl : public UObject
{
	GENERATED_BODY()

public:
	UMSettingsLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMSettingsLvl(const FVector& TargetLocation);
};
