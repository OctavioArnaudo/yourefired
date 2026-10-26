#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IVictoryLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIVictoryLvl : public UObject
{
	GENERATED_BODY()

public:
	UIVictoryLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIVictoryLvl(const FVector& TargetLocation);
};
