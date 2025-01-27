#include "MoveLeftUp.h"
#include "TurnUpRight.h"
#include "TurnDownRight.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const MoveLeftUp MoveFSM::StateMoveLeftUp;
MoveLeftUp::MoveLeftUp()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
	GridOffset = sf::Vector2i(-1, 0);
}

const MoveState* MoveLeftUp::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState = &MoveFSM::StateTurnDownRight;

	if (chead->GetGridPos().x > 0 && !MushroomManager::TestCell(chead->GetGridPos().x - 1, chead->GetGridPos().y))
	{
		chead->ScaleSprite(2.0, -2.0);
		return &MoveFSM::StateMoveLeftUp;
	}
	else if (chead->GetGridPos().y > MushroomManager::PLAY_AREA_CAP) {
		return &MoveFSM::StateTurnUpRight;
	}

	return pNextState;
}

void MoveLeftUp::Show() const
{
	ConsoleMsg::WriteLine("MoveLeftUp");
}