#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MActorSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMActorSpawner : public UObject
{
	GENERATED_BODY()

public:
	UMActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMActorSpawner(const FVector& TargetLocation);
};
