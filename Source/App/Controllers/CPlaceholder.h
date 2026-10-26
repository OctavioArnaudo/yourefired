#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlaceholder(const FVector& TargetLocation);
};
