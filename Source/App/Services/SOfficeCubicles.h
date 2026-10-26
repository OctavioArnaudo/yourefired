#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficeCubicles.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficeCubicles : public UObject
{
	GENERATED_BODY()

public:
	USOfficeCubicles();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficeCubicles(const FVector& TargetLocation);
};
