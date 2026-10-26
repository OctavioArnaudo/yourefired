#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPickup : public UObject
{
	GENERATED_BODY()

public:
	UVPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPickup(const FVector& TargetLocation);
};
