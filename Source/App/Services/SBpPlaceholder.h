#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USBpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USBpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSBpPlaceholder(const FVector& TargetLocation);
};
