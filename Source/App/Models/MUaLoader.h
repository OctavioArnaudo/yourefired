#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MUaLoader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMUaLoader : public UObject
{
	GENERATED_BODY()

public:
	UMUaLoader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMUaLoader(const FVector& TargetLocation);
};
