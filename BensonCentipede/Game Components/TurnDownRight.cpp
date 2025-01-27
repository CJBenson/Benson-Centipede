#include "TurnDownRight.h"
#include "MoveRightDown.h"
#include "TurnDownLeft.h"
#include "TurnUpLeft.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const TurnDownRight MoveFSM::StateTurnDownRight;
TurnDownRight::TurnDownRight()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndRight;
	GridOffset = sf::Vector2i(0, 1);
}

const MoveState* TurnDownRight::GetNextState(CentipedeHead* chead) const
{
	if (chead->GetPoison() && chead->GetGridPos().y < MushroomManager::GRID_V - 2)
		return &MoveFSM::StateTurnDownLeft;
	if (chead->GetGridPos().y >= MushroomManager::GRID_V - 1)
		chead->SetPoison(false);

	if (chead->GetGridPos().x < MushroomManager::GRID_H - 1 && !MushroomManager::TestCell(chead->GetGridPos().x + 1, chead->GetGridPos().y)) {
		chead->ScaleSprite(-2.0, 2.0);
		return &MoveFSM::StateMoveRightDown;
	}
	else {
		if (chead->GetGridPos().y < MushroomManager::GRID_V - 1) {
			chead->ScaleSprite(2.0, 2.0);
			return &MoveFSM::StateTurnDownLeft;
		}
		else {
			chead->ScaleSprite(2.0, -2.0);
			return &MoveFSM::StateTurnUpLeft;
		}
	}
}

void TurnDownRight::Show() const
{
	ConsoleMsg::WriteLine("TurnDownRight");
}