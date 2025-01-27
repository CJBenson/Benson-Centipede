#ifndef _Mushroom
#define _Mushroom

#include "TEAL\CommonElements.h"


class Bullet;
class MushroomManager;
class CmdScore;
class Spider;

class Mushroom : public GameObject
{
public:
	Mushroom();
	Mushroom(const Mushroom& r) = delete;
	Mushroom& operator =(const Mushroom& r) = delete;
	~Mushroom() = default;

	void Initialize(int x, int y);

	virtual void Draw();
	virtual void Destroy();

	void Die();

	void RuntimeRemove();
	sf::Vector2f GetPosition(); //returns PIXEL POSITION, not grid position
	void Poison();
	bool IsPoisoned();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);
	void Collision(Spider* other);

	static const int MAX_HEALTH = 4;
private:
	bool poisoned;

	int currHealth;

	int xPos;
	int yPos;

	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	CmdScore* pDeath;
};

#endif _Mushroom
