#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPilotLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPilotLvl : public UObject
{
	GENERATED_BODY()

public:
	UMPilotLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPilotLvl(const FVector& TargetLocation);
};
