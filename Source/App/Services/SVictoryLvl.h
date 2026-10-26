#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SVictoryLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USVictoryLvl : public UObject
{
	GENERATED_BODY()

public:
	USVictoryLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSVictoryLvl(const FVector& TargetLocation);
};
