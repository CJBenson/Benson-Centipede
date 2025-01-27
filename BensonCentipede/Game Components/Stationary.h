#ifndef _Stationary
#define _Stationary

#include "MoveState.h"

class Stationary : public MoveState
{
public:
	Stationary();
	Stationary(const Stationary& r) = delete;
	Stationary& operator =(const Stationary& r) = delete;
	~Stationary() = default;

	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;

	virtual void Show() const override;
};

#endif _Stationary
