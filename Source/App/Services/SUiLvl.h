#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SUiLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USUiLvl : public UObject
{
	GENERATED_BODY()

public:
	USUiLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSUiLvl(const FVector& TargetLocation);
};
