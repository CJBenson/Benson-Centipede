#ifndef _TurnUpRight
#define _TurnUpRight

#include "MoveState.h"

class CentipedeHead;
class TurnUpRight : public MoveState
{
public:
	TurnUpRight();
	TurnUpRight(const TurnUpRight& r) = delete;
	TurnUpRight& operator =(const TurnUpRight& r) = delete;
	~TurnUpRight() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _TurnUpRight