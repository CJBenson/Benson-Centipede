#include "TurnUpLeft.h"
#include "MoveLeftUp.h"
#include "TurnUpRight.h"
#include "TurnDownRight.h"
#include "MovementCollection.h"
#include "MushroomManager.h"
#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "MoveFSM.h"
#include "TEAL\CommonElements.h"


const TurnUpLeft MoveFSM::StateTurnUpLeft;
TurnUpLeft::TurnUpLeft()
{
	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndLeft;
	GridOffset = sf::Vector2i(0, -1);
}

const MoveState* TurnUpLeft::GetNextState(CentipedeHead* chead) const
{
	if (chead->GetGridPos().x > 0 && !MushroomManager::TestCell(chead->GetGridPos().x - 1, chead->GetGridPos().y)) {
		chead->ScaleSprite(2.0, -2.0);
		return &MoveFSM::StateMoveLeftUp;
	}
	else {
		if (chead->GetGridPos().y > MushroomManager::PLAY_AREA_CAP) {
			chead->ScaleSprite(-2.0, -2.0);
			return &MoveFSM::StateTurnUpRight;
		}
		else {
			chead->ScaleSprite(-2.0, 2.0);
			return &MoveFSM::StateTurnDownRight;
		}
	}
}

void TurnUpLeft::Show() const
{
	ConsoleMsg::WriteLine("TurnUpLeft");
}