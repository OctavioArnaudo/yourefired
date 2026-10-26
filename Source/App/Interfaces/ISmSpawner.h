#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ISmSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UISmSpawner : public UObject
{
	GENERATED_BODY()

public:
	UISmSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessISmSpawner(const FVector& TargetLocation);
};
