#include "PlayerManager.h"
#include "GameManager.h"
#include "HUDManager.h"
#include "Player.h"
#include "MushroomManager.h"
#include "MushroomGrid.h"
#include "KeyboardSystem.h"
#include "AIControl.h"

PlayerManager::PlayerManager()
{
	P1 = nullptr;
	P2 = nullptr;
	AI = nullptr;

	twoPlayer = false;

	currentPlayer = nullptr;

	myBlaster = nullptr;

	keyboard = nullptr;
	ai = nullptr;
}

PlayerManager::~PlayerManager()
{
	delete P1;
	delete P2;
	delete AI;
}

Player* PlayerManager::GetCurrent()
{
	return currentPlayer;
}

void PlayerManager::Swap()
{
	//Remove a life on the HUD for whichever player's turn it is right now
	if (currentPlayer == P1)
		GameManager::AccessHudManager()->SetPlayer1Lives(currentPlayer->GetLives() - 1);
	else if (currentPlayer == P2)
		GameManager::AccessHudManager()->SetPlayer2Lives(currentPlayer->GetLives() - 1);

	//Swap players if applicable
	if (twoPlayer) {
		if (currentPlayer == P1 && P2->GetLives() > 0)
			ChangePlayers(P2);
		else if (currentPlayer == P2 && P1->GetLives() > 0)
			ChangePlayers(P1);
		//if nobody has any lives left, game is over
		else {
			GameManager::StartAttractorMode();
		}
	}
	//if not two player, but lives still run out
	else if (currentPlayer->GetLives() <= 0)
		GameManager::StartAttractorMode();
}
void PlayerManager::ChangePlayers(Player* newPlayer)
{
	currentPlayer->GetGrid()->StoreGrid();
	currentPlayer->SetBlaster(nullptr);

	currentPlayer = newPlayer;
	currentPlayer->SetBlaster(myBlaster);
	MushroomManager::SetCurrentGrid(currentPlayer->GetGrid());
}


void PlayerManager::AddScoreToCurrent(int val)
{
	currentPlayer->AddScore(val);

	if (currentPlayer == P1)
		GameManager::AccessHudManager()->SetPlayer1Score(currentPlayer->GetScore());
	else if (currentPlayer == P2)
		GameManager::AccessHudManager()->SetPlayer2Score(currentPlayer->GetScore());
}
void PlayerManager::GetBothScores(int& s1, int& s2)
{
	if (P1 != nullptr && P2 != nullptr) {
		s1 = P1->GetScore();
		s2 = P2->GetScore();
	}
}
void PlayerManager::SetBlaster(Blaster* b)
{
	myBlaster = b;

	if (keyboard != nullptr)
		keyboard->SetBlaster(myBlaster);
	if (ai != nullptr)
		ai->SetBlaster(myBlaster);

	if(currentPlayer != nullptr)
		currentPlayer->SetBlaster(myBlaster);
}

void PlayerManager::PlayMode(bool tP)
{
	twoPlayer = tP;

	keyboard = new KeyboardSystem(myBlaster);

	P1 = new Player();
	P1->SetControlStrategy(keyboard);
	GameManager::AccessHudManager()->SetPlayer1Score(00000);
	GameManager::AccessHudManager()->SetPlayer1Lives(2);
	P1->GetGrid()->RandomSpawn();
	

	if (tP) 
	{
		P2 = new Player();
		P2->SetControlStrategy(keyboard);
		GameManager::AccessHudManager()->SetPlayer2Score(00000);
		GameManager::AccessHudManager()->SetPlayer2Lives(2);
		P2->GetGrid()->RandomSpawn();
	}

	currentPlayer = P1;
	currentPlayer->SetBlaster(myBlaster);
	MushroomManager::SetCurrentGrid(currentPlayer->GetGrid());
}
void PlayerManager::AttractorMode() 
{
	ai = new AIControl(myBlaster);

	AI = new Player();
	AI->SetControlStrategy(ai);
	AI->SetBlaster(myBlaster);
	AI->SetLives(9999);

	currentPlayer = AI;
	AI->GetGrid()->RandomSpawn();
	MushroomManager::SetCurrentGrid(currentPlayer->GetGrid());
}