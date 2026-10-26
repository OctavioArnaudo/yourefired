#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSmPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCSmPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCSmPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCSmPlaceholder(const FVector& TargetLocation);
};
