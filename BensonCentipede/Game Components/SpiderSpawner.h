#ifndef _SpiderSpawner
#define _SpiderSpawner

#include "TEAL/CommonElements.h"

class SpiderSpawner : public GameObject
{
public:
	SpiderSpawner();
	SpiderSpawner(const SpiderSpawner& r) = delete;
	SpiderSpawner& operator =(const SpiderSpawner& r) = delete;
	~SpiderSpawner() = default;

	void WaveValues(bool a, float f);
	
	virtual void Destroy();

	void Activate();
	void Deactivate();

	virtual void Alarm0();

private:
	bool active;
	float frequency;
};
#endif _SpiderSpawner
