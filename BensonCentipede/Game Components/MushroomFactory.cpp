#include "MushroomFactory.h"

MushroomFactory* MushroomFactory::ptrInstance = nullptr;

Mushroom* MushroomFactory::privCreateMushroom(int x, int y)
{
	Mushroom* m = mushroomPool.GetMushroom();

	m->SetExternalManagement(RecycleMushroom);

	m->Initialize(x, y);

	return m;
}
void MushroomFactory::privRecycleMushroom(GameObject* b)
{
	mushroomPool.ReturnMushroom(static_cast<Mushroom*>(b));
}

void MushroomFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}