#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CDoor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCDoor : public UObject
{
	GENERATED_BODY()

public:
	UCDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCDoor(const FVector& TargetLocation);
};
