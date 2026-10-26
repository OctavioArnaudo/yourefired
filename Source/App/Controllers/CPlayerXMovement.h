#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerXMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerXMovement : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerXMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerXMovement(const FVector& TargetLocation);
};
