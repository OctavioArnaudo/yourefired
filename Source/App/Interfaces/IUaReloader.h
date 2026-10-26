#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IUaReloader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIUaReloader : public UObject
{
	GENERATED_BODY()

public:
	UIUaReloader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIUaReloader(const FVector& TargetLocation);
};
