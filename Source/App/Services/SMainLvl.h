#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SMainLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USMainLvl : public UObject
{
	GENERATED_BODY()

public:
	USMainLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSMainLvl(const FVector& TargetLocation);
};
