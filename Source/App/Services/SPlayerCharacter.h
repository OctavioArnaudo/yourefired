#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SPlayerCharacter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USPlayerCharacter : public UObject
{
	GENERATED_BODY()

public:
	USPlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSPlayerCharacter(const FVector& TargetLocation);
};
