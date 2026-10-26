#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CStaticPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCStaticPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCStaticPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCStaticPlaceholder(const FVector& TargetLocation);
};
