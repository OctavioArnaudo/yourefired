#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSignaturePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCSignaturePickup : public UObject
{
	GENERATED_BODY()

public:
	UCSignaturePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCSignaturePickup(const FVector& TargetLocation);
};
