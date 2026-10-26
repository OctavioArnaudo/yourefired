#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IDynamicPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIDynamicPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIDynamicPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIDynamicPlaceholder(const FVector& TargetLocation);
};
