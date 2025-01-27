#ifndef _CentipedeHead
#define _CentipedeHead

#include "TEAL\CommonElements.h"
#include "CentipedeSegment.h"


class MushroomManager;
class Blaster;
class Bullet;
class MoveState;
class CmdScore;

class CentipedeHead : public CentipedeSegment
{
public:
	CentipedeHead(sf::Vector2i startingGridPos);
	CentipedeHead(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame);
	CentipedeHead(const CentipedeHead& r) = delete;
	CentipedeHead& operator=(const CentipedeHead& r) = delete;
	~CentipedeHead() = default;

	void InitializeOrig(sf::Vector2i startingGridPos);
	void InitializePromote(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame);

	void ChangeState();
	void SetPoison(bool newPoison);
	bool GetPoison();

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Die();

	virtual void Collision(GameObject* other) {};
	void Collision(Bullet* other);

private:
	CmdScore* pDeath;
	bool poisoned;
};


#endif _CentipedeHead