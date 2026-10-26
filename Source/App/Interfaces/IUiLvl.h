#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IUiLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIUiLvl : public UObject
{
	GENERATED_BODY()

public:
	UIUiLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIUiLvl(const FVector& TargetLocation);
};
