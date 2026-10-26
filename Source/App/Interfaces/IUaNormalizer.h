#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IUaNormalizer.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIUaNormalizer : public UObject
{
	GENERATED_BODY()

public:
	UIUaNormalizer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIUaNormalizer(const FVector& TargetLocation);
};
