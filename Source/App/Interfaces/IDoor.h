#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IDoor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIDoor : public UObject
{
	GENERATED_BODY()

public:
	UIDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIDoor(const FVector& TargetLocation);
};
