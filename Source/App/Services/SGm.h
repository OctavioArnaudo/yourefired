#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SGm.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USGm : public UObject
{
	GENERATED_BODY()

public:
	USGm();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSGm(const FVector& TargetLocation);
};
