#include "Stationary.h"
#include "MoveFSM.h"


const Stationary MoveFSM::StateStationary;

Stationary::Stationary()
{
	MyMoveOffsets = &MovementCollection::OffsetsStationary;
	GridOffset = sf::Vector2i(0, 0);
}

const MoveState* Stationary::GetNextState(CentipedeHead* chead) const
{
	return &MoveFSM::StateStationary;
}

void Stationary::Show() const
{
	ConsoleMsg::WriteLine("MoveLeftDown");
}