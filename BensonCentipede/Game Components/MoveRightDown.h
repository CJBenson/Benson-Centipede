#ifndef _MoveRightDown
#define _MoveRightDown

#include "MoveState.h"

class CentipedeHead;
class MoveRightDown: public MoveState
{
public:
	MoveRightDown();
	MoveRightDown(const MoveRightDown& r) = delete;
	MoveRightDown& operator =(const MoveRightDown& r) = delete;
	~MoveRightDown() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _MoveRightDown