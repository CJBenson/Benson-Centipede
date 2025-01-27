#include "SpiderObjectPool.h"
#include "Spider.h"

SpiderObjectPool::~SpiderObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderObjectPool::GetSpider()
{
	Spider* f;

	if (recycledItems.empty())
	{
		f = new Spider();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();

		f->RegisterToCurrentScene();
	}

	return f;
}

void SpiderObjectPool::ReturnSpider(Spider* b)
{
	recycledItems.push(static_cast<Spider*>(b));
}