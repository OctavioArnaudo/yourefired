#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPatrol : public UObject
{
	GENERATED_BODY()

public:
	UIPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPatrol(const FVector& TargetLocation);
};
