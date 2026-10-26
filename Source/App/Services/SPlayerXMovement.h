#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerXMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerXMovement : public UObject
{
	GENERATED_BODY()

public:
	USPlayerXMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerXMovement(const FVector& TargetLocation);
};
