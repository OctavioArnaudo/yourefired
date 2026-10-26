#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MStaticPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMStaticPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMStaticPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMStaticPlaceholder(const FVector& TargetLocation);
};
