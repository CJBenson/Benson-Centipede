#include "MoveRightUp.h"
#include "TurnUpLeft.h"
#include "TurnDownLeft.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const MoveRightUp MoveFSM::StateMoveRightUp;
MoveRightUp::MoveRightUp()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
	GridOffset = sf::Vector2i(1, 0);
}

const MoveState* MoveRightUp::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState = &MoveFSM::StateTurnDownLeft;

	if (chead->GetGridPos().x < MushroomManager::GRID_H - 1 && !MushroomManager::TestCell(chead->GetGridPos().x + 1, chead->GetGridPos().y))
	{
		chead->ScaleSprite(-2.0, -2.0);
		return &MoveFSM::StateMoveRightUp;
	}
	else if (chead->GetGridPos().y > MushroomManager::PLAY_AREA_CAP) {
		return &MoveFSM::StateTurnUpLeft;
	}
	
	return pNextState;
}

void MoveRightUp::Show() const
{
	ConsoleMsg::WriteLine("MoveRightUp");
}