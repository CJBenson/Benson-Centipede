#include "AIControl.h"
#include "Blaster.h"
#include "MushroomManager.h"


//H and V are either 1 or -1, controls which direction horizontally or vertically to move
AIControl::AIControl(Blaster* b)
{
	H = 1;
	V = 1;
	moving = true;
	blaster = b;
	blasterSpeed = 2;
	SetAlarm(0, moveDur);
}


void AIControl::Update()
{
	if (moving) {
		TestEdges();

		if (H == 1)
			MoveRight();
		else
			MoveLeft();

		if (V == 1)
			MoveDown();
		else
			MoveUp();
	}

	FireBlaster();
}
void AIControl::Destroy()
{
	AlarmCancel(0);
}

void AIControl::Alarm0() 
{
	moving = !moving;
	SetAlarm(0, moveDur);
}

void AIControl::TestEdges()
{
	//tests for screen edges with a bit of padding, flipping its movement direction if it hits one
	if (blaster->GetPos().x >= (float)(MushroomManager::GRID_H * MushroomManager::CELL_SIZE) - edgePadding)
		H = -1;
	else if (blaster->GetPos().x <= 0.0f + edgePadding)
		H = 1;

	if (blaster->GetPos().y >= (float)((MushroomManager::GRID_V - 1)* MushroomManager::CELL_SIZE) - edgePadding)
		V = -1;
	else if (blaster->GetPos().y <= (float)(MushroomManager::PLAY_AREA_CAP * MushroomManager::CELL_SIZE) + edgePadding)
		V = 1;
}