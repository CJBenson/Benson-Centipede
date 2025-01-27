#ifndef _CentipedeSegment
#define _CentipedeSegment

#include "TEAL\CommonElements.h"

class MoveState;
class MushroomManager;
class Bullet;
class Blaster;
class CentipedeSegment : public GameObject
{
public:
	CentipedeSegment();
	CentipedeSegment(const CentipedeSegment& r) = delete;
	CentipedeSegment& operator =(const CentipedeSegment& r) = delete;
	virtual ~CentipedeSegment() = default;

	sf::Vector2f GetPosition();

	void SetNext(CentipedeSegment* newNext);
	void SetPrev(CentipedeSegment* newPrev);
	CentipedeSegment* GetNext();
	CentipedeSegment* GetPrev();

	void UpdateGridPos(sf::Vector2i add);
	sf::Vector2i GetGridPos();

	void SetState(const MoveState* newState);

	void ScaleSprite(float xScale, float yScale);

	bool IsHead() { return isHead; };

	void Promote();

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;


protected:
	bool isHead;

	int framesPassed;

	sf::Vector2i gridPos;

	const MoveState* pCurrState;

	CentipedeSegment* next = nullptr;
	CentipedeSegment* prev = nullptr;

	sf::Vector2f Pos;
	sf::Vector2f Displacement;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

};


#endif _CentipedeSegment