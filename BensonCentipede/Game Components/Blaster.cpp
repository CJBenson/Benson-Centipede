#include "Blaster.h"
#include "Bullet.h"
#include "Mushroom.h"
#include "MushroomManager.h"
#include "BulletFactory.h"
#include "BlasterExplosion.h"
#include "GameManager.h"

Blaster::Blaster()
{
	//Just GameObject Stuff
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 1, 1);

	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);

	bitmap = ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(MainSprite, bitmap, true);

	SetDrawOrder(1000);
}

void Blaster::Initialize()
{
	//Blaster Specifics
	SPEED = 6;
	bulletOffset = 8;
	alive = true;

	Pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2.0f, (WindowManager::Window().getView().getSize().y) - (MainSprite.getTextureRect().height / 2.0f));
	Displacement = sf::Vector2f(0, 0);


	//Registration
	RegisterCollision<Blaster>(*this);

	RegisterInput(InputFlags::KeyPressed);
}

sf::Vector2f Blaster::GetPos() 
{
	return sf::Vector2f(Pos.x, Pos.y);
}

void Blaster::Fire()
{
	if(alive)
		BulletFactory::CreateBullet(this);
}

//Separate death from destruction
void Blaster::Die()
{
	alive = false;
	BlasterExplosion* boom = new BlasterExplosion(Pos);

	GameManager::BlasterDeath();

	MarkForDestroy();
}
void Blaster::Destroy()
{
	DeregisterCollision<Blaster>(*this);
	DeregisterInput();
}

void Blaster::Update()
{
	Pos += Displacement;

	//Keep Blaster's movement within player area bounds
	Tools::Clamp<float>(Pos.x, (float)MainSprite.getTextureRect().width / 2.0f, WindowManager::Window().getView().getSize().x - MainSprite.getTextureRect().width / 2.0f);
	Tools::Clamp<float>(Pos.y, WindowManager::Window().getView().getSize().y - (PLAYER_AREA_CAP - MainSprite.getTextureRect().height / 2.0f), (WindowManager::Window().getView().getSize().y - MainSprite.getTextureRect().height / 2.0f) - MushroomManager::CELL_SIZE);

	MainSprite.setPosition(Pos);
	MainSprite.Update();

	Displacement = sf::Vector2f(0, 0); //No continuous movement after key is released
}

//Called by InputSystem
void Blaster::Up() {
	Displacement += sf::Vector2f(0, -SPEED);
}
void Blaster::Down() {
	Displacement += sf::Vector2f(0, SPEED);
}
void Blaster::Left() {
	Displacement += sf::Vector2f(-SPEED, 0);
}
void Blaster::Right() {
	Displacement += sf::Vector2f(SPEED, 0);
}

//Dependent on real player or AI
void Blaster::SetSpeed(float nS) 
{
	SPEED = nS;
}

void Blaster::Collision(Mushroom* other)
{
	//Take mushroom's position and find the difference in position between blaster & mushroom
	sf::Vector2f otherPos = other->GetPosition();

	float xDiff = Pos.x - otherPos.x;
	float yDiff = Pos.y - otherPos.y;

	//Approaching from horizontal direction
	if (abs(xDiff) > abs(yDiff)) {
		float changeAmt = MainSprite.getTextureRect().width - abs(xDiff); //amt to move back by


		//Move back in the direction you came from
		if (xDiff > 0)
			Pos += sf::Vector2f(changeAmt, 0);
		else if (xDiff < 0)
			Pos += sf::Vector2f(-changeAmt, 0);
	}

	//Approaching from vertical direction
	else if (abs(yDiff) > abs(xDiff)) {
		float changeAmt = MainSprite.getTextureRect().height - abs(yDiff);

		if (yDiff > 0)
			Pos += sf::Vector2f(0, changeAmt);
		else if (yDiff < 0)
			Pos += sf::Vector2f(0, -changeAmt);
	}
}

void Blaster::Collision(Flea* other)
{
	Die();
}
void Blaster::Collision(CentipedeSegment* other)
{
	Die();
}
void Blaster::Collision(Spider* other)
{
	Die();
}

void Blaster::Draw() {
	WindowManager::Window().draw(MainSprite);
}