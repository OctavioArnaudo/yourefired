#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IWorldLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIWorldLvl : public UObject
{
	GENERATED_BODY()

public:
	UIWorldLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIWorldLvl(const FVector& TargetLocation);
};
