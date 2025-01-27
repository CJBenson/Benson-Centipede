#include "Scorpion.h"
#include "ScorpionFactory.h"
#include "Mushroom.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "GameManager.h"

Scorpion::Scorpion()
{
	SPEED = 2;

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1);
	MainSprite.SetAnimation(0, 3);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Scorpion>(*this);

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::ScorpionKilled);

	SetDrawOrder(800);
}


void Scorpion::Initialize(int yPos)
{
	float xPos;

	if (rand() % 2 == 0) {
		xPos = 0.0f;
		Displacement = sf::Vector2f(SPEED, 0);
		MainSprite.setScale(-1, 1);
	}
	else {
		xPos = (MushroomManager::GRID_H + 0.5f) * 16.0f;
		Displacement = sf::Vector2f(-SPEED, 0);
		MainSprite.setScale(1, 1);
	}

	ScorpionFactory::AddToActive(this);

	pDeath->SetManager(GameManager::AccessScoreManager());

	RegisterCollision<Scorpion>(*this);
	Pos = sf::Vector2f(xPos, (yPos + 0.5f) * 16.0f);
	MainSprite.setPosition(Pos);
}


void Scorpion::Update()
{
	MainSprite.setPosition(Pos);
	MainSprite.Update();

	Pos += Displacement;

	if (Pos.x > MushroomManager::GRID_H * 17.0f || Pos.x < -1.0) {
		ScorpionFactory::RemoveFromActive(this);
		MarkForDestroy();
	}
}
void Scorpion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}


void Scorpion::Collision(Bullet* other)
{
	Die();
}
void Scorpion::Collision(Mushroom* other)
{
	other->Poison();
}


void Scorpion::Die()
{
	GameManager::AccessScoreManager()->SendScoreCmd(pDeath);
	ScorpionFactory::RemoveFromActive(this);

	MarkForDestroy();
}


void Scorpion::Destroy()
{
	DeregisterCollision<Scorpion>(*this);
}