#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlaceholder(const FVector& TargetLocation);
};
