#ifndef _Spider
#define _Spider

#include "TEAL\CommonElements.h"
#include "MushroomManager.h"

class Mushroom;
class Blaster;
class Bullet;
class CmdScore;
class Spider : public GameObject
{
public:
	Spider();
	Spider(const Spider& r) = delete;
	Spider& operator =(const Spider& r) = delete;
	~Spider() = default;

	void Initialize();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Die();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

	sf::Vector2f GetPos();

	virtual void Alarm0();

	void ChangeDirection();


private:
	float SPEED;

	const float startingY = MushroomManager::CELL_SIZE * 27.5;
	const float upperLimit = MushroomManager::CELL_SIZE * 20.5;
	
	sf::Vector2f BulletPos;
	sf::Vector2f Pos;
	sf::Vector2f Displacement;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	CmdScore* pDeath;
};

#endif _Spider
