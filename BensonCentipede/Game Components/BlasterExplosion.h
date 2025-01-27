#ifndef _BlasterExplosion
#define _BlasterExplosion

#include "TEAL\CommonElements.h"

class BlasterExplosion : public GameObject
{
public:
	BlasterExplosion() = delete;
	BlasterExplosion(const BlasterExplosion& r) = delete;
	BlasterExplosion& operator =(const BlasterExplosion& r) = delete;
	~BlasterExplosion() = default;

	BlasterExplosion(sf::Vector2f position);

	virtual void Update();
	virtual void Draw();

private:
	sf::Vector2f Pos;

	AnimatedSprite MainSprite;
};

#endif _BlasterExplosion