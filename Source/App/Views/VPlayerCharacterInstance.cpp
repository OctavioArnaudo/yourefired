#include "VPlayerCharacterInstance.h"

VPlayerCharacterInstance::VPlayerCharacterInstance()
{
}

void VPlayerCharacterInstance::SetupVisuals(ACharacter* CharacterOwner, UStaticMeshComponent*& OutMesh, USpringArmComponent*& OutBoom, UCameraComponent*& OutCamera)
{
	if (!CharacterOwner) return;

	Spawn.BuildPlayerMesh(CharacterOwner, OutMesh);
	Camera.BuildCameraComponents(CharacterOwner, OutBoom, OutCamera);
}
