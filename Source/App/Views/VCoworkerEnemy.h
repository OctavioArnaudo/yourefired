#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VCoworkerEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVCoworkerEnemy : public UObject
{
	GENERATED_BODY()

public:
	UVCoworkerEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVCoworkerEnemy(const FVector& TargetLocation);
};
