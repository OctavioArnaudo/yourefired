#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VVictoryLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVVictoryLvl : public UObject
{
	GENERATED_BODY()

public:
	UVVictoryLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVVictoryLvl(const FVector& TargetLocation);
};
