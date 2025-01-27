#include "FleaObjectPool.h"
#include "Flea.h"

FleaObjectPool::FleaObjectPool()
{

}
FleaObjectPool::~FleaObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaObjectPool::GetFlea()
{
	Flea* f;

	if (recycledItems.empty())
	{
		f = new Flea();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();

		f->RegisterToCurrentScene();
	}

	return f;
}

void FleaObjectPool::ReturnFlea(Flea* b)
{
	recycledItems.push(static_cast<Flea*>(b));
}