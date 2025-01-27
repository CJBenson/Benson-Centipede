#ifndef _Scorpion
#define _Scorpion

#include "TEAL/CommonElements.h"

class Bullet;
class Mushroom;
class CmdScore;
class Scorpion : public GameObject
{
public:
	Scorpion();
	Scorpion(const Scorpion& r) = delete;
	Scorpion& operator =(const Scorpion& r) = delete;
	~Scorpion() = default;

	void Initialize(int yPos);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Die();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);
	void Collision(Mushroom* other);

private:
	float SPEED;

	sf::Vector2f Pos;
	sf::Vector2f Displacement;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	CmdScore* pDeath;
};
#endif _Scorpion
