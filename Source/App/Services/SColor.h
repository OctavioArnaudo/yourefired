#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SColor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USColor : public UObject
{
	GENERATED_BODY()

public:
	USColor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSColor(const FVector& TargetLocation);
};
