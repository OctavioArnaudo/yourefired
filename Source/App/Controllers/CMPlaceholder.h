#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CMPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCMPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCMPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCMPlaceholder(const FVector& TargetLocation);
};
