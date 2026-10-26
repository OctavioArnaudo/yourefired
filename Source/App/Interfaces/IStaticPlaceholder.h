#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IStaticPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIStaticPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIStaticPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIStaticPlaceholder(const FVector& TargetLocation);
};
