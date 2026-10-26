#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SWorldLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USWorldLvl : public UObject
{
	GENERATED_BODY()

public:
	USWorldLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSWorldLvl(const FVector& TargetLocation);
};
