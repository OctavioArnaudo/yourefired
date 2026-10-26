#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPilotLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPilotLvl : public UObject
{
	GENERATED_BODY()

public:
	USPilotLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPilotLvl(const FVector& TargetLocation);
};
