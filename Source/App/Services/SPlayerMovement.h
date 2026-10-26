#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerMovement : public UObject
{
	GENERATED_BODY()

public:
	USPlayerMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerMovement(const FVector& TargetLocation);
};
