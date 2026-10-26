#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOfficePatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIOfficePatrol : public UObject
{
	GENERATED_BODY()

public:
	UIOfficePatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIOfficePatrol(const FVector& TargetLocation);
};
