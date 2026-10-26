#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SSmPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USSmPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	USSmPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSSmPlaceholder(const FVector& TargetLocation);
};
