#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VEnvironment.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVEnvironment : public UObject
{
	GENERATED_BODY()

public:
	UVEnvironment();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVEnvironment(const FVector& TargetLocation);
};
