#include "MoveRightDown.h"
#include "TurnDownLeft.h"
#include "TurnUpLeft.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const MoveRightDown MoveFSM::StateMoveRightDown;
MoveRightDown::MoveRightDown()
{
	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
	GridOffset = sf::Vector2i(1, 0);
}

const MoveState* MoveRightDown::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState = nullptr;

	if (chead->GetGridPos().x < MushroomManager::GRID_H - 1 && !MushroomManager::TestCell(chead->GetGridPos().x + 1, chead->GetGridPos().y))
	{
		chead->ScaleSprite(-2.0, 2.0);
		return &MoveFSM::StateMoveRightDown;
	}
	else if (chead->GetGridPos().y < MushroomManager::GRID_V - 2) {
		if (MushroomManager::TestPoison(chead->GetGridPos().x + 1, chead->GetGridPos().y))
			chead->SetPoison(true);

		return &MoveFSM::StateTurnDownLeft;
	}

	return &MoveFSM::StateTurnUpLeft;
}

void MoveRightDown::Show() const
{
	ConsoleMsg::WriteLine("MoveRightDown");
}