#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MCoworkerEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMCoworkerEnemy : public UObject
{
	GENERATED_BODY()

public:
	UMCoworkerEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMCoworkerEnemy(const FVector& TargetLocation);
};
