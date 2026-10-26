#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VStaticPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVStaticPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVStaticPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVStaticPlaceholder(const FVector& TargetLocation);
};
