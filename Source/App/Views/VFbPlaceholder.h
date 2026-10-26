#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VFbPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVFbPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVFbPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVFbPlaceholder(const FVector& TargetLocation);
};
