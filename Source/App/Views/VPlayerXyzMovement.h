#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerXyzMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerXyzMovement : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerXyzMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerXyzMovement(const FVector& TargetLocation);
};
