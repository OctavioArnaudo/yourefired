#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCEnemy : public UObject
{
	GENERATED_BODY()

public:
	UCEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCEnemy(const FVector& TargetLocation);
};
