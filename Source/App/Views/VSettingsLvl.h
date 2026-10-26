#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VSettingsLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVSettingsLvl : public UObject
{
	GENERATED_BODY()

public:
	UVSettingsLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVSettingsLvl(const FVector& TargetLocation);
};
