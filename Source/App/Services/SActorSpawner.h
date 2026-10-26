#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SActorSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USActorSpawner : public UObject
{
	GENERATED_BODY()

public:
	USActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSActorSpawner(const FVector& TargetLocation);
};
