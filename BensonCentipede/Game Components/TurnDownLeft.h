#ifndef _TurnDownLeft
#define _TurnDownLeft

#include "MoveState.h"

class CentipedeHead;
class TurnDownLeft : public MoveState
{
public:
	TurnDownLeft();
	TurnDownLeft(const TurnDownLeft& r) = delete;
	TurnDownLeft& operator =(const TurnDownLeft& r) = delete;
	~TurnDownLeft() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _TurnDownLeft