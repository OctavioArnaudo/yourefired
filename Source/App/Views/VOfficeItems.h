#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficeItems.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficeItems : public UObject
{
	GENERATED_BODY()

public:
	UVOfficeItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficeItems(const FVector& TargetLocation);
};
