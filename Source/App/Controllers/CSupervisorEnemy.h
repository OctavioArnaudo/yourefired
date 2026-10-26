#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CSupervisorEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCSupervisorEnemy : public UObject
{
	GENERATED_BODY()

public:
	UCSupervisorEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCSupervisorEnemy(const FVector& TargetLocation);
};
