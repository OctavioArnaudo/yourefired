#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPickup : public UObject
{
	GENERATED_BODY()

public:
	UIPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPickup(const FVector& TargetLocation);
};
