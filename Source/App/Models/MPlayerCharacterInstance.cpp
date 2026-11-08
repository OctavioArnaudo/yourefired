#include "MPlayerCharacterInstance.h"

MPlayerCharacterInstance::MPlayerCharacterInstance()
	: WalkSpeed(400.0f)
	, SprintSpeed(750.0f)
	, bIsSprinting(false)
	, RangedSpawnOffset(100.0f)
	, ShootModel(nullptr)
{
}

UMShoot* MPlayerCharacterInstance::GetShootModel()
{
	if (!ShootModel)
	{
		ShootModel = NewObject<UMShoot>();
		if (ShootModel)
		{
			ShootModel->FireRate = 0.25f;
		}
	}
	return ShootModel;
}
