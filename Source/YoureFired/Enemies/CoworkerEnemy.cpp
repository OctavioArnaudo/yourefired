#include "CoworkerEnemy.h"

ACoworkerEnemy::ACoworkerEnemy()
{
	Health = 30.0f;
	StressDamage = 8.0f;
	AttackRange = 200.0f;
}

void ACoworkerEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ACoworkerEnemy::StartGossipChatter()
{
	UE_LOG(LogTemp, Log, TEXT("Coworker traps player in useless workplace gossip, raising stress!"));
	AttackPlayer();
}
