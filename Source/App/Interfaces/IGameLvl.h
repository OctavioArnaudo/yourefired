#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IGameLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIGameLvl : public UObject
{
	GENERATED_BODY()

public:
	UIGameLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIGameLvl(const FVector& TargetLocation);
};
