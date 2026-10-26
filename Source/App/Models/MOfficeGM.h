#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficeGM.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficeGM : public UObject
{
	GENERATED_BODY()

public:
	UMOfficeGM();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficeGM(const FVector& TargetLocation);
};
