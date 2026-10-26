#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VDoor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVDoor : public UObject
{
	GENERATED_BODY()

public:
	UVDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVDoor(const FVector& TargetLocation);
};
