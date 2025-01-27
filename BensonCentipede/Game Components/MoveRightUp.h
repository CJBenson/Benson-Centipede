#ifndef _MoveRightUp
#define _MoveRightUp

#include "MoveState.h"

class CentipedeHead;
class MoveRightUp : public MoveState
{
public:
	MoveRightUp();
	MoveRightUp(const MoveRightUp& r) = delete;
	MoveRightUp& operator =(const MoveRightUp& r) = delete;
	~MoveRightUp() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _MoveRightUp