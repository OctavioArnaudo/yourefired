#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerMovement : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerMovement(const FVector& TargetLocation);
};
