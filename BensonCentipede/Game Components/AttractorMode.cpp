//Self
#include "AttractorMode.h"
#include "AttractorController.h"
//GameObjects
#include "Blaster.h"
#include "Mushroom.h"
#include "Bullet.h"
#include "Flea.h"
#include "Scorpion.h"
#include "Spider.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
//Systems
#include "GameManager.h"

void AttractorMode::Initialize()
{
	ConsoleMsg::WriteLine("Starting Attractor Mode!");

	new AttractorController;
	GameManager::InitializeAttractorMode();

	CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Blaster, Mushroom>();
	CollisionTestPair<Blaster, Flea>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Blaster, CentipedeHead>();
	CollisionTestPair<Bullet, CentipedeHead>();
	CollisionTestPair<Scorpion, Bullet>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<CentipedeBody, Bullet>();
	CollisionTestPair<CentipedeBody, Blaster>();
	CollisionTestPair<Mushroom, Spider>();
	CollisionTestPair<Spider, Blaster>();
	CollisionTestPair<Spider, Bullet>();
}

void AttractorMode::Terminate()
{
	GameManager::CritterCleanup();
}