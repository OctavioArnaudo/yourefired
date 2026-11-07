#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPatrol.generated.h"

class ACharacter;

UCLASS(BlueprintType, Blueprintable)
class APP_API USPatrol : public UObject
{
	GENERATED_BODY()

public:
	USPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPatrol(const FVector& TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Services")
	void ExecutePatrolStep(ACharacter* Character, const FVector& HomeLocation, float PatrolRadius);
};
