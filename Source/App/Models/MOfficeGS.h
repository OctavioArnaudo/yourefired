#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficeGS.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficeGS : public UObject
{
	GENERATED_BODY()

public:
	UMOfficeGS();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficeGS(const FVector& TargetLocation);
};
