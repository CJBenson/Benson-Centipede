// GameStart.cpp
// Andre Berthiaume, July 2019

#include "Game.h"
#include "..\GameManager.h"

void Game::GameEnd()
{
	GameManager::Terminate();
}