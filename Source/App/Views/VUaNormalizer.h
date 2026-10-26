#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VUaNormalizer.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVUaNormalizer : public UObject
{
	GENERATED_BODY()

public:
	UVUaNormalizer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVUaNormalizer(const FVector& TargetLocation);
};
