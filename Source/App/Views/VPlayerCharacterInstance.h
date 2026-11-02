#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

class APP_API VPlayerCharacterInstance
{
public:
	VPlayerCharacterInstance();

	void SetupVisuals(ACharacter* CharacterOwner, UStaticMeshComponent*& OutMesh, USpringArmComponent*& OutBoom, UCameraComponent*& OutCamera);
};
