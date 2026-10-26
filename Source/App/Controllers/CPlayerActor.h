#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerActor : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerActor(const FVector& TargetLocation);
};
