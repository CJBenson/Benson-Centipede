#include "MoveLeftDown.h"
#include "TurnDownRight.h"
#include "TurnUpRight.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"

const MoveLeftDown MoveFSM::StateMoveLeftDown;


MoveLeftDown::MoveLeftDown()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
	GridOffset = sf::Vector2i(-1, 0);
}

const MoveState* MoveLeftDown::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState = &MoveFSM::StateTurnUpRight;

	if (chead->GetGridPos().x > 0 && !MushroomManager::TestCell(chead->GetGridPos().x - 1, chead->GetGridPos().y))
	{
		chead->ScaleSprite(2.0, 2.0);
		return &MoveFSM::StateMoveLeftDown;
	}
	else if(chead->GetGridPos().y < MushroomManager::GRID_V - 2){
		if (MushroomManager::TestPoison(chead->GetGridPos().x - 1, chead->GetGridPos().y))
			chead->SetPoison(true);

		return &MoveFSM::StateTurnDownRight;
	}

	return pNextState;
}

void MoveLeftDown::Show() const
{
	ConsoleMsg::WriteLine("MoveLeftDown");
}
