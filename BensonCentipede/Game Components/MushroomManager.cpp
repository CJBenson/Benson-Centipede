#include "MushroomManager.h"
#include "Mushroom.h"
#include "FleaSpawner.h"
#include "MushroomGrid.h"
#include <cmath>

MushroomManager* MushroomManager::ptrInstance = nullptr;

MushroomManager::MushroomManager() 
{
	fs = nullptr;

	currGrid = nullptr;
}


void MushroomManager::privAddShroom(int xPos, int yPos) 
{
	currGrid->AddShroom(xPos, yPos);
}
void MushroomManager::privRemoveShroom(int xPos, int yPos)
{
	currGrid->RemoveShroom(xPos, yPos);

	fs->CheckShrooms(); //flea spawner checks if it's got the right amt of shrooms to spawn
}


bool MushroomManager::privTestCell(int x, int y)
{
	return currGrid->TestCell(x, y);
}
bool MushroomManager::privTestPoison(int x, int y)
{
	return currGrid->TestCell(x, y) && currGrid->GetShroom(x, y)->IsPoisoned();
}
int MushroomManager::privShroomsInPA()
{
	int count = 0;

	for (int i = 0; i < GRID_H; i++) {
		for (int j = PLAY_AREA_CAP; j < GRID_V; j++) {
			if (currGrid->TestCell(i, j))
				count += 1;
		}
	}

	return count;
}


void MushroomManager::privSetFS(FleaSpawner* flea)
{
	fs = flea;
}
void MushroomManager::privSetGrid(MushroomGrid* nG)
{
	currGrid = nG;
	currGrid->ConstructGrid();
}


void MushroomManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}