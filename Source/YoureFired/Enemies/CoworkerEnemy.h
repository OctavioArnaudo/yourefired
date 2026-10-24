#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "CoworkerEnemy.generated.h"

/**
 * Coworker Enemy - Distracts player with idle chatter, gossip, and useless tasks, raising stress.
 */
UCLASS()
class YOUREFIRED_API ACoworkerEnemy : public AEnemyBase
{
	GENERATED_BODY()

public:
	ACoworkerEnemy();

protected:
	virtual void BeginPlay() override;

public:
	/** Specific gossip / chatter attack */
	UFUNCTION(BlueprintCallable, Category = "Coworker Actions")
	void StartGossipChatter();
};
