#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerImc.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerImc : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerImc();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerImc(const FVector& TargetLocation);
};
