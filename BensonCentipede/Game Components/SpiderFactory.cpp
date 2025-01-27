#include "SpiderFactory.h"
#include "Spider.h"

SpiderFactory* SpiderFactory::ptrInstance = nullptr;

void SpiderFactory::privCreateSpider()
{
	Spider* s = spiderPool.GetSpider();

	s->SetExternalManagement(RecycleSpider);

	s->Initialize();
}
void SpiderFactory::privRecycleSpider(GameObject* b)
{
	spiderPool.ReturnSpider(static_cast<Spider*>(b));
}


void SpiderFactory::privCleanup()
{
	while (!activeSpiders.empty())
	{
		Spider* s = activeSpiders.front();
		activeSpiders.pop_front();
		s->MarkForDestroy();
	}
}
void SpiderFactory::privAddToActive(Spider* s)
{
	activeSpiders.push_back(s);
}
void SpiderFactory::privRemoveFromActive(Spider* s)
{
	activeSpiders.remove(s);
}


void SpiderFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}