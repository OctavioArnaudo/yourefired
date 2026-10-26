#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ISettingsLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UISettingsLvl : public UObject
{
	GENERATED_BODY()

public:
	UISettingsLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessISettingsLvl(const FVector& TargetLocation);
};
