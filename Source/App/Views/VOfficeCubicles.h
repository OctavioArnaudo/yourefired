#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficeCubicles.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficeCubicles : public UObject
{
	GENERATED_BODY()

public:
	UVOfficeCubicles();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficeCubicles(const FVector& TargetLocation);
};
