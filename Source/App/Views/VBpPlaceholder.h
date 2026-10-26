#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VBpPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVBpPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVBpPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVBpPlaceholder(const FVector& TargetLocation);
};
