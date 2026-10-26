#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerXMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerXMovement : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerXMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerXMovement(const FVector& TargetLocation);
};
