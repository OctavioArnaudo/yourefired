#include "MPlayerCharacterInstance.h"

MPlayerCharacterInstance::MPlayerCharacterInstance()
	: WalkSpeed(400.0f)
	, SprintSpeed(750.0f)
	, bIsSprinting(false)
	, RangedSpawnOffset(100.0f)
	, ShootModel(nullptr)
{
	ShootModel = NewObject<UMShoot>();
	if (ShootModel)
	{
		ShootModel->FireRate = 0.25f; // Discrete player fire rate (4 shots per second max when held)
	}
}
