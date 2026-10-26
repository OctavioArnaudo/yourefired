#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SUaReloader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USUaReloader : public UObject
{
	GENERATED_BODY()

public:
	USUaReloader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSUaReloader(const FVector& TargetLocation);
};
