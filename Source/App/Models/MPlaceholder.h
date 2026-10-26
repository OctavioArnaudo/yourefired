#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UMPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlaceholder(const FVector& TargetLocation);
};
