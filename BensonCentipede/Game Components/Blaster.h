#ifndef _Blaster
#define _Blaster

#include "TEAL\CommonElements.h"

//forward declarations
class Bullet;
class Mushroom;
class Flea;
class Spider;
class CentipedeSegment;

class Blaster : public GameObject
{
public:

	Blaster();
	Blaster(const Blaster& r) = delete;
	Blaster& operator =(const Blaster& r) = delete;
	~Blaster() = default;

	void Initialize();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Die();

	sf::Vector2f GetPos(); //For updating bullet position when loaded

	void Up();
	void Down();
	void Left();
	void Right();
	void Fire();

	void SetSpeed(float nS);

	virtual void Collision(GameObject* other){};
	void Collision(Mushroom* other);
	void Collision(Flea* other);
	void Collision(CentipedeSegment* other);
	void Collision(Spider* other);

private:
	bool alive;
	float SPEED;
	float bulletOffset; //vertical space between blaster/bullet when loaded
	const float PLAYER_AREA_CAP = 112.0f; //Vertical Limit to player movement

	sf::Vector2f Pos;
	sf::Vector2f Displacement;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	
};


#endif _Blaster
