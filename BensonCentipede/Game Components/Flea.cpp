#include "Flea.h"
#include "FleaFactory.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "GameManager.h"

Flea::Flea() 
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2);
	MainSprite.SetAnimation(0, 3);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	bitmap = ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, bitmap, true);

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::FleaKilled);

	SetDrawOrder(800);
}

void Flea::Initialize(int xPos)
{
	SPEED = 4;

	health = 2;

	gridY = -1;

	framesPassed = 0;

	mushrooms = true;

	Pos = sf::Vector2f(xPos * 16.0f + (MainSprite.getTextureRect().width / 2.0f), 0.0f);
	MainSprite.setPosition(Pos);
	Displacement = sf::Vector2f(0, 0);

	FleaFactory::AddToActive(this);

	pDeath->SetManager(GameManager::AccessScoreManager());

	RegisterCollision<Flea>(*this);
}

void Flea::Update()
{
	Displacement = sf::Vector2f(0, SPEED);
	Pos += Displacement;

	Displacement = sf::Vector2f(0, 0);

	MainSprite.setPosition(Pos);
	MainSprite.Update();

	//Screen Bottom Limit
	if (Pos.y >= WindowManager::Window().getView().getSize().y) {
		FleaFactory::RemoveFromActive(this);
		MarkForDestroy();
	}
	
	//Every grid cell, checks for mushroom spawn ability
	if (framesPassed == MushroomManager::CELL_SIZE / SPEED) {
		gridY += 1;
		framesPassed = 0;

		SpawnShroom();
	}

	framesPassed++;
}

void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::Die()
{
	GameManager::AccessScoreManager()->SendScoreCmd(pDeath);
	FleaFactory::RemoveFromActive(this);
	MarkForDestroy();
}

void Flea::Destroy()
{
	DeregisterCollision<Flea>(*this);
}

void Flea::SpawnShroom()
{
	int chance = rand() % shroomChance;

	if (chance == 0 && mushrooms && gridY < MushroomManager::GRID_V - 2 && gridY > 0) {
		MushroomManager::AddShroom((int)(Pos.x / 16) - 1, gridY);
	}
}

void Flea::Collision(Bullet* other)
{
	health--;
	if (health <= 0) {
		Die();
	}
	if (health == 1) {
		SPEED = 8;
		mushrooms = false; //turns off mushroom spawning
	}
}
