#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CCoworkerEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCCoworkerEnemy : public UObject
{
	GENERATED_BODY()

public:
	UCCoworkerEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCCoworkerEnemy(const FVector& TargetLocation);
};
