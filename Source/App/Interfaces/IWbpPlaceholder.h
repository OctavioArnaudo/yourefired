#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IWbpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIWbpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIWbpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIWbpPlaceholder(const FVector& TargetLocation);
};
