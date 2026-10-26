#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficeGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficeGm : public UObject
{
	GENERATED_BODY()

public:
	UVOfficeGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficeGm(const FVector& TargetLocation);
};
