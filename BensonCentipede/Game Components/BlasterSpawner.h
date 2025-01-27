#ifndef _BlasterSpawner
#define _BlasterSpawner

#include "TEAL\CommonElements.h"

class BlasterSpawner : public GameObject
{
public:
	BlasterSpawner() = default;
	BlasterSpawner(const BlasterSpawner& r) = delete;
	BlasterSpawner& operator =(const BlasterSpawner& r) = delete;
	~BlasterSpawner() = default;

	virtual void Destroy();

	void SpawnBlaster();
	virtual void Alarm0();

	const float RESPAWN_TIME = 2.0f;
};

#endif _BlasterSpawner