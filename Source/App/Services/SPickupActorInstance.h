#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPickupActorInstance.generated.h"

class UWorld;
class AActor;

UCLASS(BlueprintType, Blueprintable)
class APP_API USPickupActorInstance : public UObject
{
	GENERATED_BODY()

public:
	USPickupActorInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	AActor* SpawnHealthPickup(UWorld* World, const FVector& Location);
};
