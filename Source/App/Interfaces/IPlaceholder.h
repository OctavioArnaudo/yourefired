#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlaceholder(const FVector& TargetLocation);
};
