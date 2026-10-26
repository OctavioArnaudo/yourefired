#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VSmSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVSmSpawner : public UObject
{
	GENERATED_BODY()

public:
	UVSmSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVSmSpawner(const FVector& TargetLocation);
};
