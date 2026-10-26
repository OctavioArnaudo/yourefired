#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerXyMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerXyMovement : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerXyMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerXyMovement(const FVector& TargetLocation);
};
