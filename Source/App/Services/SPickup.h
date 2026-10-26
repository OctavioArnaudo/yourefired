#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPickup : public UObject
{
	GENERATED_BODY()

public:
	USPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPickup(const FVector& TargetLocation);
};
