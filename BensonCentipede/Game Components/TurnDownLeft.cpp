#include "TurnDownLeft.h"
#include "MoveLeftDown.h"
#include "TurnDownRight.h"
#include "TurnUpRight.H"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const TurnDownLeft MoveFSM::StateTurnDownLeft;
TurnDownLeft::TurnDownLeft()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndLeft;
	GridOffset = sf::Vector2i(0, 1);
}

const MoveState* TurnDownLeft::GetNextState(CentipedeHead* chead) const
{
	if (chead->GetPoison() && chead->GetGridPos().y < MushroomManager::GRID_V - 2)
		return &MoveFSM::StateTurnDownRight;
	if (chead->GetGridPos().y >= MushroomManager::GRID_V - 1)
		chead->SetPoison(false);

	if (chead->GetGridPos().x > 0 && !MushroomManager::TestCell(chead->GetGridPos().x - 1, chead->GetGridPos().y))
	{
		chead->ScaleSprite(2.0, 2.0);
		return &MoveFSM::StateMoveLeftDown;
	}
	else {
		if (chead->GetGridPos().y < MushroomManager::GRID_V - 1) {
			chead->ScaleSprite(-2.0, 2.0);
			return &MoveFSM::StateTurnDownRight;
		}
		else {
			chead->ScaleSprite(-2.0, -2.0);
			return &MoveFSM::StateTurnUpRight;
		}
	}
}

void TurnDownLeft::Show() const
{
	ConsoleMsg::WriteLine("TurnDownLeft");
}