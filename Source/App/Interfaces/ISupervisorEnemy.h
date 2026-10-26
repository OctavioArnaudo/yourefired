#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ISupervisorEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UISupervisorEnemy : public UObject
{
	GENERATED_BODY()

public:
	UISupervisorEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessISupervisorEnemy(const FVector& TargetLocation);
};
