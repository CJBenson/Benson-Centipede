#ifndef _MushroomFactory
#define _MushroomFactory

#include "TEAL\CommonElements.h"
#include "MushroomObjectPool.h"
#include "Mushroom.h"

class SpriteSheet;

class MushroomFactory
{
private:
	static MushroomFactory* ptrInstance;

	static MushroomFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new MushroomFactory();
		return *ptrInstance;
	}

	MushroomFactory() = default;
	MushroomFactory(const MushroomFactory&) = delete;
	MushroomFactory& operator=(const MushroomFactory&) = delete;
	~MushroomFactory() = default;

	MushroomObjectPool mushroomPool;

	Mushroom* privCreateMushroom(int x, int y);
	void privRecycleMushroom(GameObject* b);

public:
	static Mushroom* CreateMushroom(int x, int y) { return Instance().privCreateMushroom(x, y); }
	static void RecycleMushroom(GameObject* b) { Instance().privRecycleMushroom(b); }

	static void Terminate();
};

#endif _MushroomFactory
