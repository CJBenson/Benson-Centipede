#ifndef _MoveLeftUp
#define _MoveLeftUp

#include "MoveState.h"

class CentipedeHead;
class MoveLeftUp : public MoveState
{
public:
	MoveLeftUp();
	MoveLeftUp(const MoveLeftUp& r) = delete;
	MoveLeftUp& operator =(const MoveLeftUp& r) = delete;
	~MoveLeftUp() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};


#endif _MoveLeftUp