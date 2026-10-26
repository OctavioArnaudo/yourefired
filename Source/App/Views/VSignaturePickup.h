#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VSignaturePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVSignaturePickup : public UObject
{
	GENERATED_BODY()

public:
	UVSignaturePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVSignaturePickup(const FVector& TargetLocation);
};
