#ifndef _MoveState
#define _MoveState
#include "MovementCollection.h"
#include "TEAL/CommonElements.h"

class CentipedeHead;
struct OffsetArray;
class CentipedeSegment;
class MoveState
{
public:
	MoveState() {};
	MoveState(const MoveState& r) = delete;
	MoveState& operator =(const MoveState& r) = delete;
	~MoveState() = default;

	const OffsetArray* GetMoveOffsets() const { return MyMoveOffsets; }
	const sf::Vector2i GetGridOffset() const { return GridOffset; }
	virtual const MoveState* GetNextState(CentipedeHead* chead) const = 0;
	virtual void Show() const = 0;

protected:
	const OffsetArray* MyMoveOffsets = nullptr;	
	sf::Vector2i GridOffset;
};


#endif _MoveState
