#include "SpiderSpawner.h"
#include "SpiderFactory.h"

SpiderSpawner::SpiderSpawner()
{
	active = true;

	frequency = 7.0f;
}

void SpiderSpawner::WaveValues(bool a, float f)
{
	active = a;
	frequency = f;

	if (active == true)
		Activate();
}

void SpiderSpawner::Activate()
{
	SetAlarm(0, frequency);
}
void SpiderSpawner::Deactivate()
{
	active = false;
}

void SpiderSpawner::Destroy()
{
	AlarmCancel(0);
}

void SpiderSpawner::Alarm0() 
{
	SpiderFactory::CreateSpider();

	if(active)
		SetAlarm(0, frequency);
}