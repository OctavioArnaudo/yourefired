#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficeGs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficeGs : public UObject
{
	GENERATED_BODY()

public:
	USOfficeGs();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficeGs(const FVector& TargetLocation);
};
