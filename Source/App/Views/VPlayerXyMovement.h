#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlayerXyMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlayerXyMovement : public UObject
{
	GENERATED_BODY()

public:
	UVPlayerXyMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlayerXyMovement(const FVector& TargetLocation);
};
