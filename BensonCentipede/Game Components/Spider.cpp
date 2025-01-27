#include "Spider.h"
#include "SpiderFactory.h"
#include "Mushroom.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "GameManager.h"
#include <cmath>

Spider::Spider()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);
	MainSprite.SetAnimation(0, 7);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);

	bitmap = ResourceManager::GetTextureBitmap("Spider");
	SetCollider(MainSprite, bitmap, true);

	SPEED = 2.0f;

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::SpiderKilled);
}


void Spider::Initialize()
{
	int rando = rand() % 2;

	if (rando == 0) {
		Pos = sf::Vector2f(0.0f, startingY);
		SPEED = 2.0f;
	}
	else if (rando == 1)
	{
		Pos = sf::Vector2f(MushroomManager::GRID_H * MushroomManager::CELL_SIZE, startingY);
		SPEED = -2.0f;
	}

	Displacement = sf::Vector2f(SPEED, SPEED);
	

	MainSprite.setPosition(Pos);

	SpiderFactory::AddToActive(this);

	RegisterCollision<Spider>(*this);

	pDeath->SetManager(GameManager::AccessScoreManager());

	SetAlarm(0, 0.5f);
}


void Spider::Alarm0()
{
	ChangeDirection();
	
	SetAlarm(0, 0.75f);
}


void Spider::ChangeDirection()
{
	int random = rand() % 2;

	if (random == 0)
		Displacement = sf::Vector2f(SPEED, SPEED);
	else if (random == 1)
		Displacement = sf::Vector2f(0.0f, SPEED);
}


void Spider::Update()
{
	Pos += Displacement;

	if (Pos.y <= upperLimit)
		Displacement = sf::Vector2f(Displacement.x, abs(Displacement.y));
	if((Pos.y > (MushroomManager::GRID_V - 2) * MushroomManager::CELL_SIZE))
		Displacement = sf::Vector2f(Displacement.x, -abs(Displacement.y));

	if (Pos.x > MushroomManager::GRID_H * 17.0f || Pos.x < -1.0) {
		SpiderFactory::RemoveFromActive(this);
		MarkForDestroy();
	}

	MainSprite.Update();
	MainSprite.setPosition(Pos);


}
void Spider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}


void Spider::Destroy()
{
	DeregisterCollision<Spider>(*this);
	AlarmCancel(0);
}


void Spider::Die()
{
	GameManager::AccessScoreManager()->SendScoreCmd(pDeath);
	SpiderFactory::RemoveFromActive(this);

	MarkForDestroy();
}

void Spider::Collision(Bullet* other)
{
	Die();
}

sf::Vector2f Spider::GetPos()
{
	return Pos;
}