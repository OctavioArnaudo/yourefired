#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SUaNormalizer.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USUaNormalizer : public UObject
{
	GENERATED_BODY()

public:
	USUaNormalizer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSUaNormalizer(const FVector& TargetLocation);
};
