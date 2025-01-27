
#include "Bullet.h"
#include "Blaster.h"
#include "BulletFactory.h"

Bullet::Bullet()
{
	SPEED = 15;

	bitmap = ResourceManager::GetTextureBitmap("Bullet");

	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Bullet"), 1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	SetCollider(MainSprite, bitmap);
}

void Bullet::Initialize(Blaster* blast)
{
	blaster = blast;
	Pos = blast->GetPos();

	MainSprite.setPosition(Pos);

	BulletFactory::SetBulletOnScreen(true); //BulletFactory knows whether bullet is currently on screen

	RegisterCollision<Bullet>(*this);
}

void Bullet::Update()
{
	Displacement = sf::Vector2f(0, -SPEED); //Constant displacement throughout the entire time
	Pos += Displacement;
	Displacement = sf::Vector2f(0, 0);

	if (Pos.y <= 0) {
		MarkForDestroy();
	}

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Bullet::Collision(Mushroom* other) {
	MarkForDestroy();
}

void Bullet::Collision(Flea* other) {
	MarkForDestroy();
}

void Bullet::Collision(CentipedeSegment* other) {
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Spider* other)
{
	MarkForDestroy();
}

void Bullet::Destroy()
{
	BulletFactory::SetBulletOnScreen(false); //A-ok for firing again

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Fires again if the button is held down
		blaster->Fire();

	DeregisterCollision<Bullet>(*this);
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

