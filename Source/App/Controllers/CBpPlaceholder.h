#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CBpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCBpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCBpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCBpPlaceholder(const FVector& TargetLocation);
};
