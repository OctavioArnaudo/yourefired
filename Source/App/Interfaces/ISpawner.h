#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ISpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UISpawner : public UObject
{
	GENERATED_BODY()

public:
	UISpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessISpawner(const FVector& TargetLocation);
};
