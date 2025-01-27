#include "Mushroom.h"
#include "Bullet.h"
#include "MushroomManager.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "GameManager.h"

Mushroom::Mushroom() 
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(MainSprite, bitmap, true);

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::MushroomKilled);
	
	SetDrawOrder(500);
}

void Mushroom::Initialize(int x, int y) 
{
	poisoned = false;

	xPos = x;
	yPos = y;

	currHealth = MAX_HEALTH;

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);
	MainSprite.SetAnimation(0, 3);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	Pos = sf::Vector2f((float)(xPos * MushroomManager::CELL_SIZE) + MainSprite.getTextureRect().width / 2.0f, (float)(yPos * MushroomManager::CELL_SIZE) + MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);

	pDeath->SetManager(GameManager::AccessScoreManager());

	SetDrawOrder(500);

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Mushroom>(*this);
}

sf::Vector2f Mushroom::GetPosition() {
	return this->Pos;
}

void Mushroom::Poison()
{
	poisoned = true;
	MainSprite.SetAnimation(4, 7);
	for (int i = 0; i < MAX_HEALTH - currHealth; i++)
		MainSprite.NextFrame();
}
bool Mushroom::IsPoisoned()
{
	return poisoned;
}

void Mushroom::Draw() 
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Die()
{
	GameManager::AccessScoreManager()->SendScoreCmd(pDeath);
	RuntimeRemove();
}

void Mushroom::Destroy() 
{
	DeregisterCollision<Mushroom>(*this);
}
void Mushroom::RuntimeRemove()
{
	MushroomManager::RemoveShroom(xPos, yPos);
	MarkForDestroy();
}

void Mushroom::Collision(Bullet* other) {
	currHealth--;
	if (currHealth <= 0) {
		Die();
		return;
	}
	MainSprite.NextFrame();
}
void Mushroom::Collision(Spider* other)
{
	currHealth = 0;
	RuntimeRemove();
}