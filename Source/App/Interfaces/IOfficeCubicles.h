#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOfficeCubicles.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIOfficeCubicles : public UObject
{
	GENERATED_BODY()

public:
	UIOfficeCubicles();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIOfficeCubicles(const FVector& TargetLocation);
};
