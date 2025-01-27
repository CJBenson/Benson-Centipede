#ifndef _MoveLeftDown
#define _MoveLeftDown

#include "MoveState.h"

class CentipedeHead;
class MoveLeftDown : public MoveState
{
public:
	MoveLeftDown();
	MoveLeftDown(const MoveLeftDown& r) = delete;
	MoveLeftDown& operator =(const MoveLeftDown& r) = delete;
	~MoveLeftDown() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _MoveLeftDown