#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VMPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVMPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVMPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVMPlaceholder(const FVector& TargetLocation);
};
