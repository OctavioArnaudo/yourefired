#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerXyMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerXyMovement : public UObject
{
	GENERATED_BODY()

public:
	USPlayerXyMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerXyMovement(const FVector& TargetLocation);
};
