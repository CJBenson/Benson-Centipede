#ifndef _CentipedeBody
#define _CentipedeBody

#include "CentipedeSegment.h"

class CmdScore;
class CentipedeBody : public CentipedeSegment
{
public:
	CentipedeBody(sf::Vector2i startingGridPos);
	CentipedeBody(const CentipedeBody& r) = delete;
	CentipedeBody& operator=(const CentipedeBody& r) = delete;
	~CentipedeBody() = default;

	void Initialize(sf::Vector2i startingGridPos);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Die();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

private:
	CmdScore* pDeath;
};

#endif _CentipedeBody