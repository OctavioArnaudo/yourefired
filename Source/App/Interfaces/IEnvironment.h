#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IEnvironment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIEnvironment : public UObject
{
	GENERATED_BODY()

public:
	UIEnvironment();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIEnvironment(const FVector& TargetLocation);
};
