#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SCoworkerEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USCoworkerEnemy : public UObject
{
	GENERATED_BODY()

public:
	USCoworkerEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSCoworkerEnemy(const FVector& TargetLocation);
};
