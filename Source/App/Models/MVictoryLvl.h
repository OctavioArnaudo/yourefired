#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MVictoryLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMVictoryLvl : public UObject
{
	GENERATED_BODY()

public:
	UMVictoryLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMVictoryLvl(const FVector& TargetLocation);
};
