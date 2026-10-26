#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerXyzMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerXyzMovement : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerXyzMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerXyzMovement(const FVector& TargetLocation);
};
