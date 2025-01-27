#include "ScorpionFactory.h"
#include "Scorpion.h"

ScorpionFactory* ScorpionFactory::ptrInstance = nullptr;

void ScorpionFactory::privCreateScorpion(int yPos)
{
	Scorpion* s = scorpionPool.GetScorpion();

	s->SetExternalManagement(RecycleScorpion);

	s->Initialize(yPos);
}
void ScorpionFactory::privRecycleScorpion(GameObject* s)
{
	scorpionPool.ReturnScorpion(static_cast<Scorpion*>(s));
}


void ScorpionFactory::privCleanup()
{
	while (!activeScorps.empty())
	{
		Scorpion* s = activeScorps.front();
		activeScorps.pop_front();
		s->MarkForDestroy();
	}
}
void ScorpionFactory::privAddToActive(Scorpion* s)
{
	activeScorps.push_back(s);
}
void ScorpionFactory::privRemoveFromActive(Scorpion* s) 
{
	activeScorps.remove(s);
}

void ScorpionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}