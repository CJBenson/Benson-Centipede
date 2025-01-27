#ifndef _Flea
#define _Flea

#include "TEAL/CommonElements.h"

class Blaster;
class Bullet;
class MushroomManager;
class CmdScore;

class Flea : public GameObject
{
public:
	Flea();
	Flea(const Flea& r) = delete;
	Flea& operator =(const Flea& r) = delete;
	~Flea() = default;

	void Initialize(int xPos);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Die();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

	void SpawnShroom();

private:
	bool mushrooms;

	float SPEED;
	int health;

	static const int shroomChance = 5; //1 in 5 chance to spawn each cell

	int framesPassed;
	int gridY;

	sf::Vector2f Pos;
	sf::Vector2f Displacement;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	CmdScore* pDeath;
};

#endif _Flea