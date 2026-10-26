#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USLvl : public UObject
{
	GENERATED_BODY()

public:
	USLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSLvl(const FVector& TargetLocation);
};
