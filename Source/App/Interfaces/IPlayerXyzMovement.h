#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerXyzMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerXyzMovement : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerXyzMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerXyzMovement(const FVector& TargetLocation);
};
