#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VActorSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVActorSpawner : public UObject
{
	GENERATED_BODY()

public:
	UVActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVActorSpawner(const FVector& TargetLocation);
};
