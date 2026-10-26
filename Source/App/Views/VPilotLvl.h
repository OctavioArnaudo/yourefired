#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPilotLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPilotLvl : public UObject
{
	GENERATED_BODY()

public:
	UVPilotLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPilotLvl(const FVector& TargetLocation);
};
