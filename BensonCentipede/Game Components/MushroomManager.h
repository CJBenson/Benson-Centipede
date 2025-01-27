#ifndef _MushroomManager
#define _MushroomManager

#include "TEAL\CommonElements.h"

class Mushroom;
class FleaSpawner;
class MushroomGrid;

class MushroomManager
{
public:
	//Add & Remove take in GRID POSITION, not pixel position
	static void AddShroom(int xPos, int yPos) { Instance().privAddShroom(xPos, yPos); };
	static void RemoveShroom(int xPos, int yPos) { Instance().privRemoveShroom(xPos, yPos); };

	//Mushroom Inquiries
	static bool TestCell(int x, int y) { return Instance().privTestCell(x, y); }; //is there a mushroom here
	static bool TestPoison(int x, int y) { return Instance().privTestPoison(x, y); }; //is there a poison mushroom here
	static int ShroomsInPA() { return Instance().privShroomsInPA(); }; //how many mushrooms are in player area

	//the part where i do things weird and bad maybe
	static void SetFleaSpawner(FleaSpawner* flea) { Instance().privSetFS(flea); };
	static void SetCurrentGrid(MushroomGrid* nG) { Instance().privSetGrid(nG); };

	static void Terminate();

	static const int GRID_H = 30;
	static const int GRID_V = 32;
	static const int CELL_SIZE = 16; //size of cell in pixels
	static const int PLAY_AREA_CAP = 26; //grid position of player cap

private:
	//I couldn't bring myself to convert this one from being a singleton... I use it everywhere
	static MushroomManager* ptrInstance;

	static MushroomManager& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new MushroomManager();
		return *ptrInstance;
	}

	MushroomManager();
	MushroomManager(const MushroomManager& r) = delete;
	MushroomManager& operator =(const MushroomManager& r) = delete;
	~MushroomManager() = default;

	void privAddShroom(int xPos, int yPos);
	void privRemoveShroom(int xPos, int yPos);

	bool privTestCell(int x, int y);
	bool privTestPoison(int x, int y);
	int privShroomsInPA();

	void privSetFS(FleaSpawner* flea);
	void privSetGrid(MushroomGrid* nG);

	MushroomGrid* currGrid;
	FleaSpawner* fs;
};


#endif _MushroomManager
