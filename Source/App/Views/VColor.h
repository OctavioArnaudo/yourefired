#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VColor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVColor : public UObject
{
	GENERATED_BODY()

public:
	UVColor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVColor(const FVector& TargetLocation);
};
