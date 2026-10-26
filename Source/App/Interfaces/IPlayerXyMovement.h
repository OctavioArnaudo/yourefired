#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerXyMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerXyMovement : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerXyMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerXyMovement(const FVector& TargetLocation);
};
