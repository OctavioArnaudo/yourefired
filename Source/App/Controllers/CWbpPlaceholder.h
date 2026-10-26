#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWbpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCWbpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCWbpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCWbpPlaceholder(const FVector& TargetLocation);
};
