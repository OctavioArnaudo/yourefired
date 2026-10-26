#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOfficeActors.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIOfficeActors : public UObject
{
	GENERATED_BODY()

public:
	UIOfficeActors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIOfficeActors(const FVector& TargetLocation);
};
