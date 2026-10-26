#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDefeatLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USDefeatLvl : public UObject
{
	GENERATED_BODY()

public:
	USDefeatLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSDefeatLvl(const FVector& TargetLocation);
};
