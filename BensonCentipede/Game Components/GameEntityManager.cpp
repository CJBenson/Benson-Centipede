#include "GameEntityManager.h"

//Spawners
#include "CentipedeSpawner.h"
#include "FleaSpawner.h"
#include "MushroomManager.h"
#include "ScorpionSpawner.h"
#include "SpiderSpawner.h"
#include "BlasterSpawner.h"
//Factories
#include "CentipedeFactory.h"
#include "FleaFactory.h"
#include "ScorpionFactory.h"
#include "SpiderFactory.h"
#include "BlasterFactory.h"
//Other
#include "Wave.h"

GameEntityManager::GameEntityManager()
{
	centipedeSpawner = nullptr;
	fleaSpawner = nullptr;
	scorpionSpawner = nullptr;
	spiderSpawner = nullptr;
	blasterSpawner = nullptr;
}

//Spawners get destroyed at scene end so it needs to create new ones every scene start
void GameEntityManager::CreateNewSpawners()
{
	centipedeSpawner = new CentipedeSpawner();
	fleaSpawner = new FleaSpawner();
	scorpionSpawner = new ScorpionSpawner();
	spiderSpawner = new SpiderSpawner();
	blasterSpawner = new BlasterSpawner();
}

void GameEntityManager::SwitchWaveData(Wave newData)
{
	centipedeSpawner->WaveValues(newData.soloHeads, newData.segmentNum, newData.centiSpeed);
	fleaSpawner->WaveValues(newData.fleaActive, newData.minShrooms);
	scorpionSpawner->WaveValues(newData.scorpActive, newData.scorpFreq);
	spiderSpawner->WaveValues(newData.spiderActive, newData.spiderFreq);

	centipedeSpawner->SpawnCentipede();
}


void GameEntityManager::CritterCleanup()
{
	CentipedeFactory::Cleanup();
	FleaFactory::Cleanup();
	ScorpionFactory::Cleanup();
	SpiderFactory::Cleanup();
}

//GameManager calls this when blaster dies
void GameEntityManager::RespawnBlaster()
{
	blasterSpawner->SetAlarm(0, blasterSpawner->RESPAWN_TIME);
}