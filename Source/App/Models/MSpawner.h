#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMSpawner : public UObject
{
	GENERATED_BODY()

public:
	UMSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMSpawner(const FVector& TargetLocation);
};
