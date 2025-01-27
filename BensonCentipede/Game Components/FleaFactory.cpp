#include "FleaFactory.h"
#include "MushroomManager.h"
#include "FleaObjectPool.h"
#include "Flea.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;


void FleaFactory::privCreateFlea(int xPos)
{
	Flea* f = fleaPool.GetFlea();

	f->SetExternalManagement(RecycleFlea);

	f->Initialize(xPos);
}

void FleaFactory::privRecycleFlea(GameObject* b)
{
	fleaPool.ReturnFlea(static_cast<Flea*>(b));
}

void FleaFactory::privCleanup()
{
	while (!activeFleas.empty())
	{
		Flea* f = activeFleas.front();
		activeFleas.pop_front();
		f->MarkForDestroy();
	}
}
void FleaFactory::privAddToActive(Flea* f)
{
	activeFleas.push_back(f);
}
void FleaFactory::privRemoveFromActive(Flea* f)
{
	activeFleas.remove(f);
}

void FleaFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}