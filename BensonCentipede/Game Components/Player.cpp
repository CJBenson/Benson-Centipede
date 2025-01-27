#include "Player.h"
#include "KeyboardSystem.h"
#include "MushroomGrid.h"
#include "Blaster.h"

Player::Player(): currWave(1), currScore(0)
{
	livesLeft = START_LIVES;
	myBlaster = nullptr;
	controlStrategy = nullptr;
	myGrid = new MushroomGrid();
}
Player::~Player()
{
	delete myGrid;
}

void Player::AddScore(int amt)
{
	currScore += amt;
	ConsoleMsg::WriteLine("Current Player Score: " + Tools::ToString(currScore));
}
int Player::GetScore()
{
	return currScore;
}


int Player::GetWave()
{
	return currWave;
}
void Player::SetWave(int newWave)
{
	currWave = newWave;
}

MushroomGrid* Player::GetGrid()
{
	return myGrid;
}


void Player::SetControlStrategy(InputSystem* cs)
{
	controlStrategy = cs;
}


void Player::SetBlaster(Blaster* b)
{
	myBlaster = b;
	controlStrategy->SetBlaster(myBlaster);
}


void Player::SetLives(int l)
{
	livesLeft = l;
}
int Player::GetLives()
{
	return livesLeft;
}


void Player::Die()
{
	livesLeft -= 1;

	ConsoleMsg::WriteLine("Player Lives: " + Tools::ToString(livesLeft));

	if (livesLeft <= 0) 
	{

	}
}