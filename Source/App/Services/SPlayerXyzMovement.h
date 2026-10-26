#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerXyzMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerXyzMovement : public UObject
{
	GENERATED_BODY()

public:
	USPlayerXyzMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerXyzMovement(const FVector& TargetLocation);
};
