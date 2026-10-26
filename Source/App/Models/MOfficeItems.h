#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficeItems.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficeItems : public UObject
{
	GENERATED_BODY()

public:
	UMOfficeItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficeItems(const FVector& TargetLocation);
};
