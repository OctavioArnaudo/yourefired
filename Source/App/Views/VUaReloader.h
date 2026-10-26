#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VUaReloader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVUaReloader : public UObject
{
	GENERATED_BODY()

public:
	UVUaReloader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVUaReloader(const FVector& TargetLocation);
};
