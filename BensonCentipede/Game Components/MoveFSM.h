#ifndef _MoveFSM
#define _MoveFSM

class MoveRightDown;
class MoveRightUp;
class MoveLeftDown;
class MoveLeftUp;
class TurnDownLeft;
class TurnDownRight;
class TurnUpLeft;
class TurnUpRight;
class Stationary;

class MoveFSM
{
private:

public:
	static const MoveRightDown StateMoveRightDown;
	static const MoveRightUp StateMoveRightUp;
	static const MoveLeftDown StateMoveLeftDown;
	static const MoveLeftUp StateMoveLeftUp;
	static const TurnDownLeft StateTurnDownLeft;
	static const TurnDownRight StateTurnDownRight;
	static const TurnUpLeft StateTurnUpLeft;
	static const TurnUpRight StateTurnUpRight;
	static const Stationary StateStationary;
};

#endif _MoveFSM