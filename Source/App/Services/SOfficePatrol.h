#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficePatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficePatrol : public UObject
{
	GENERATED_BODY()

public:
	USOfficePatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficePatrol(const FVector& TargetLocation);
};
