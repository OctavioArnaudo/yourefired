#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVSpawner : public UObject
{
	GENERATED_BODY()

public:
	UVSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVSpawner(const FVector& TargetLocation);
};
