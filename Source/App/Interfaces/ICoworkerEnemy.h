#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ICoworkerEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UICoworkerEnemy : public UObject
{
	GENERATED_BODY()

public:
	UICoworkerEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessICoworkerEnemy(const FVector& TargetLocation);
};
