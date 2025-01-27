#include "TurnUpRight.h"
#include "MoveRightUp.h"
#include "TurnUpLeft.h"
#include "TurnDownLeft.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const TurnUpRight MoveFSM::StateTurnUpRight;
TurnUpRight::TurnUpRight()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndRight;
	GridOffset = sf::Vector2i(0, -1);
}

const MoveState* TurnUpRight::GetNextState(CentipedeHead* chead) const
{
	if (chead->GetGridPos().x < MushroomManager::GRID_H - 1 && !MushroomManager::TestCell(chead->GetGridPos().x + 1, chead->GetGridPos().y)) {
		chead->ScaleSprite(-2.0, -2.0);
		return &MoveFSM::StateMoveRightUp;
	}
	else {
		if (chead->GetGridPos().y > MushroomManager::PLAY_AREA_CAP) {
			chead->ScaleSprite(2.0, -2.0);
			return &MoveFSM::StateTurnUpLeft;
		}
		else {
			chead->ScaleSprite(2.0, 2.0);
			return &MoveFSM::StateTurnDownLeft;
		}
	}
}

void TurnUpRight::Show() const
{
	ConsoleMsg::WriteLine("TurnUpRight");
}