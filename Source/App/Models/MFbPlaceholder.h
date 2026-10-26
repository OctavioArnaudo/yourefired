#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MFbPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMFbPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMFbPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMFbPlaceholder(const FVector& TargetLocation);
};
