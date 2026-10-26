#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SSignaturePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USSignaturePickup : public UObject
{
	GENERATED_BODY()

public:
	USSignaturePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSSignaturePickup(const FVector& TargetLocation);
};
