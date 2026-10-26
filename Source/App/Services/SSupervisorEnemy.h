#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SSupervisorEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USSupervisorEnemy : public UObject
{
	GENERATED_BODY()

public:
	USSupervisorEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSSupervisorEnemy(const FVector& TargetLocation);
};
