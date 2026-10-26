#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIEnemy : public UObject
{
	GENERATED_BODY()

public:
	UIEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIEnemy(const FVector& TargetLocation);
};
