//Managers
#include "GameManager.h"
#include "WaveManager.h"
#include "PlayerManager.h"
#include "ScoreManager.h"
#include "GameEntityManager.h"
#include "MushroomManager.h"
#include "HUDManager.h"

//Factories
#include "FleaFactory.h"
#include "BulletFactory.h"
#include "ScorpionFactory.h"
#include "SpiderFactory.h"
#include "CentipedeFactory.h"
#include "BlasterFactory.h"
#include "GlyphFactory.h"
#include "MushroomFactory.h"
#include "CmdFactory.h"

//Scenes
#include "AttractorMode.h"
#include "PlayMode.h"

//Other
#include "Wave.h"
#include "Player.h"

GameManager* GameManager::ptrInstance = nullptr;

GameManager::GameManager()
{
	//no gameobjects spawned before first scene is active
	waveManager = new WaveManager();
	playerManager = new PlayerManager();
	scoreManager = nullptr;
	entityManager = new GameEntityManager();
	hudManager = new HUDManager();
	blaster = nullptr;
	twoPlayer = false;
}

//Called on Centipede Death
void GameManager::privNextWave()
{
	int nextWaveNum = playerManager->GetCurrent()->GetWave() + 1;
	privActivateWave(nextWaveNum);
	playerManager->GetCurrent()->SetWave(nextWaveNum);
}
//Called on blaster death
void GameManager::privResetWave()
{
	int currWaveNum = playerManager->GetCurrent()->GetWave();
	privActivateWave(currWaveNum);
	playerManager->GetCurrent()->SetWave(currWaveNum);
}
void GameManager::privActivateWave(int waveNum)
{
	entityManager->SwitchWaveData(waveManager->GetWaveData(waveNum));
}


//Separate scene start and initialization of game elements
void GameManager::privStartPlay(bool tP)
{
	SceneManager::ChangeScene(new PlayMode);
	twoPlayer = tP;
}
void GameManager::privInitPlay()
{
	entityManager->CreateNewSpawners();
	scoreManager = new ScoreManager(playerManager);
	hudManager->CreateHUD();

	privActivateWave(1);

	blaster = BlasterFactory::CreateBlaster();

	playerManager->SetBlaster(blaster);
	playerManager->PlayMode(twoPlayer);
}

void GameManager::privStartAttractor()
{
	SceneManager::ChangeScene(new AttractorMode);
}
void GameManager::privInitAttract()
{
	entityManager->CreateNewSpawners();
	scoreManager = new ScoreManager(playerManager);
	hudManager->CreateHUD();

	privActivateWave(1);

	blaster = BlasterFactory::CreateBlaster();

	playerManager->SetBlaster(blaster);
	playerManager->AttractorMode();
}


void GameManager::privDeath() 
{
	entityManager->RespawnBlaster();
	playerManager->GetCurrent()->Die();
	playerManager->Swap();
	privCritterCleanup();
}


void GameManager::privSetBlaster(Blaster* b) {
	blaster = b;
	playerManager->SetBlaster(blaster);
}


void GameManager::privCritterCleanup()
{
	entityManager->CritterCleanup();
}


void GameManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}


GameManager::~GameManager()
{
	delete waveManager;
	delete playerManager;
	delete entityManager;
	delete hudManager;

	BulletFactory::Terminate();
	ScorpionFactory::Terminate();
	FleaFactory::Terminate();
	CentipedeFactory::Terminate();
	BlasterFactory::Terminate();
	SpiderFactory::Terminate();
	GlyphFactory::Terminate();
	MushroomFactory::Terminate();
	MushroomManager::Terminate();
	CmdFactory::Terminate();
}