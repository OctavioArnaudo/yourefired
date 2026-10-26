#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SWbpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USWbpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USWbpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSWbpPlaceholder(const FVector& TargetLocation);
};
