#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CGameLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCGameLvl : public UObject
{
	GENERATED_BODY()

public:
	UCGameLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCGameLvl(const FVector& TargetLocation);
};
