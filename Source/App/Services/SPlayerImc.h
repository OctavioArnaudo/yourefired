#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerImc.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerImc : public UObject
{
	GENERATED_BODY()

public:
	USPlayerImc();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerImc(const FVector& TargetLocation);
};
