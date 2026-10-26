#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SMPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USMPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USMPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSMPlaceholder(const FVector& TargetLocation);
};
