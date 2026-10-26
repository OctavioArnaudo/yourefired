#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerCharacter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerCharacter : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerCharacter(const FVector& TargetLocation);
};
