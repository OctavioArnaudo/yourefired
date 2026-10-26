#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IActorSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIActorSpawner : public UObject
{
	GENERATED_BODY()

public:
	UIActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIActorSpawner(const FVector& TargetLocation);
};
