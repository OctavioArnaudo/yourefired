#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CColor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCColor : public UObject
{
	GENERATED_BODY()

public:
	UCColor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCColor(const FVector& TargetLocation);
};
