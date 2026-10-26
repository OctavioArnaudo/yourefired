#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficeGs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficeGs : public UObject
{
	GENERATED_BODY()

public:
	UVOfficeGs();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficeGs(const FVector& TargetLocation);
};
