#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPlayerActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIPlayerActor : public UObject
{
	GENERATED_BODY()

public:
	UIPlayerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIPlayerActor(const FVector& TargetLocation);
};
