#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerActor : public UObject
{
	GENERATED_BODY()

public:
	USPlayerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerActor(const FVector& TargetLocation);
};
