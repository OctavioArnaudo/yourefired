#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CActorSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCActorSpawner : public UObject
{
	GENERATED_BODY()

public:
	UCActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCActorSpawner(const FVector& TargetLocation);
};
