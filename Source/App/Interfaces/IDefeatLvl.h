#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IDefeatLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIDefeatLvl : public UObject
{
	GENERATED_BODY()

public:
	UIDefeatLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIDefeatLvl(const FVector& TargetLocation);
};
