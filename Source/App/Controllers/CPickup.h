#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPickup : public UObject
{
	GENERATED_BODY()

public:
	UCPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPickup(const FVector& TargetLocation);
};
