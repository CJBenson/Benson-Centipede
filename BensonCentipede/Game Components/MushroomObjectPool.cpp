#include "MushroomObjectPool.h"
#include "Mushroom.h"

MushroomObjectPool::~MushroomObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Mushroom* MushroomObjectPool::GetMushroom()
{
	Mushroom* f;

	if (recycledItems.empty())
	{
		f = new Mushroom();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();

		f->RegisterToCurrentScene();
	}

	return f;
}

void MushroomObjectPool::ReturnMushroom(Mushroom* b)
{
	recycledItems.push(static_cast<Mushroom*>(b));
}