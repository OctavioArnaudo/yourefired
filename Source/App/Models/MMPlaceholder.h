#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MMPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMMPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMMPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMMPlaceholder(const FVector& TargetLocation);
};
