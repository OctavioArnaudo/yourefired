#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficeGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficeGm : public UObject
{
	GENERATED_BODY()

public:
	USOfficeGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficeGm(const FVector& TargetLocation);
};
