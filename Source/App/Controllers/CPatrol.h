#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPatrol : public UObject
{
	GENERATED_BODY()

public:
	UCPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPatrol(const FVector& TargetLocation);
};
