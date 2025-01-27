#include "BlasterSpawner.h"
#include "BlasterFactory.h"
#include "GameManager.h"

void BlasterSpawner::SpawnBlaster()
{
	GameManager::SetBlaster(BlasterFactory::CreateBlaster());
}


void BlasterSpawner::Destroy()
{
	AlarmCancel(0);
}


void BlasterSpawner::Alarm0()
{
	SpawnBlaster();
	GameManager::ResetWave();
}