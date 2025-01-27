#include "BlasterObjectPool.h"
#include "Blaster.h"

BlasterObjectPool::BlasterObjectPool()
{

}
BlasterObjectPool::~BlasterObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Blaster* BlasterObjectPool::GetBlaster()
{
	Blaster* f;

	if (recycledItems.empty())
	{
		f = new Blaster();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();

		f->RegisterToCurrentScene();
	}

	return f;
}

void BlasterObjectPool::ReturnBlaster(Blaster* b)
{
	recycledItems.push(static_cast<Blaster*>(b));
}