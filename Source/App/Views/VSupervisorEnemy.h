#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VSupervisorEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVSupervisorEnemy : public UObject
{
	GENERATED_BODY()

public:
	UVSupervisorEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVSupervisorEnemy(const FVector& TargetLocation);
};
