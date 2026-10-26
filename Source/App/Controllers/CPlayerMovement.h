#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerMovement : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerMovement(const FVector& TargetLocation);
};
