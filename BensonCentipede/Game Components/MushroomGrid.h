#ifndef _MushroomGrid
#define _MushroomGrid

#include "MushroomManager.h"

class MushroomGrid
{
public:
	MushroomGrid();
	MushroomGrid(const MushroomGrid& r) = delete;
	MushroomGrid& operator =(const MushroomGrid& r) = delete;
	~MushroomGrid() = default;

	void RandomSpawn();

	void AddShroom(int x, int y);
	void RemoveShroom(int x, int y);

	Mushroom* GetShroom(int x, int y);

	bool TestCell(int x, int y);

	void StoreGrid();
	void ConstructGrid();
private:
	Mushroom* myGrid[MushroomManager::GRID_H][MushroomManager::GRID_V];
	bool gridVals[MushroomManager::GRID_H][MushroomManager::GRID_V]; //I did it the naive way

	static const int initialNum = 50; //num of mushrooms to spawn at beginning
};

#endif _MushroomGrid