#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CFbPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCFbPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UCFbPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCFbPlaceholder(const FVector& TargetLocation);
};
