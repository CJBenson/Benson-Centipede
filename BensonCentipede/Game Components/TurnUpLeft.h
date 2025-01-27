#ifndef _TurnUpLeft
#define _TurnUpLeft

#include "MoveState.h"

class CentipedeHead;
class TurnUpLeft : public MoveState
{
public:
	TurnUpLeft();
	TurnUpLeft(const TurnUpLeft& r) = delete;
	TurnUpLeft& operator =(const TurnUpLeft& r) = delete;
	~TurnUpLeft() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _TurnUpLeft