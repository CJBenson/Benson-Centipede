#ifndef _TurnDownRight
#define _TurnDownRight

#include "MoveState.h"

class CentipedeHead;
class TurnDownRight : public MoveState
{
public:
	TurnDownRight();
	TurnDownRight(const TurnDownRight& r) = delete;
	TurnDownRight& operator =(const TurnDownRight& r) = delete;
	~TurnDownRight() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _TurnDownRight