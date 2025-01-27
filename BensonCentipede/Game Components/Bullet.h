#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"

//forward declarations
class Blaster;
class Mushroom;
class Flea;
class CentipedeSegment;
class Scorpion;
class Spider;
class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(const Bullet& r) = delete;
	Bullet& operator =(const Bullet& r) = delete;
	~Bullet() = default;

	void Initialize(Blaster* blast);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* other) {};
	void Collision(Mushroom* other);
	void Collision(Flea* other);
	void Collision(CentipedeSegment* other);
	void Collision(Scorpion* other);
	void Collision(Spider* other);

	
private:
	float SPEED;

	Blaster* blaster;

	sf::Vector2f Pos;
	sf::Vector2f Displacement;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
};

#endif Bullet
