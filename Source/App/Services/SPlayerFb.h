#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerFb.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerFb : public UObject
{
	GENERATED_BODY()

public:
	USPlayerFb();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerFb(const FVector& TargetLocation);
};
