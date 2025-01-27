#include "MushroomGrid.h"
#include "Mushroom.h"
#include "MushroomFactory.h"

MushroomGrid::MushroomGrid() 
{
	for (int i = 0; i < MushroomManager::GRID_H; i++) {
		for (int j = 0; j < MushroomManager::GRID_V; j++) {
			myGrid[i][j] = nullptr;
			gridVals[i][j] = false;
		}
	}
}


void MushroomGrid::RandomSpawn()
{
	for (int i = 0; i < initialNum; i++) {
		gridVals[rand() % MushroomManager::GRID_H][rand() % (MushroomManager::GRID_V - 3) + 1] = true;
	}
}


void MushroomGrid::AddShroom(int x, int y)
{
	if (myGrid[x][y] == nullptr)
		myGrid[x][y] = MushroomFactory::CreateMushroom(x, y);
}
void MushroomGrid::RemoveShroom(int x, int y)
{
	if (myGrid[x][y] != nullptr)
		myGrid[x][y] = nullptr;
}


Mushroom* MushroomGrid::GetShroom(int x, int y)
{
	return myGrid[x][y];
}


bool MushroomGrid::TestCell(int x, int y)
{
	if (x >= MushroomManager::GRID_H || x <= -1)
		return false;

	return myGrid[x][y] != nullptr;
}


void MushroomGrid::StoreGrid()
{
	for (int i = 0; i < MushroomManager::GRID_H; i++) {
		for (int j = 0; j < MushroomManager::GRID_V; j++) {
			gridVals[i][j] = (myGrid[i][j] != nullptr);

			if(myGrid[i][j] != nullptr)
				myGrid[i][j]->RuntimeRemove();
		}
	}
}
void MushroomGrid::ConstructGrid()
{
	for (int i = 0; i < MushroomManager::GRID_H; i++) {
		for (int j = 0; j < MushroomManager::GRID_V; j++) {
			if (gridVals[i][j])
				AddShroom(i, j);
		}
	}
}