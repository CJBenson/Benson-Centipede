#ifndef _BlasterFactory
#define _BlasterFactory

#include "TEAL/CommonElements.h"
#include "BlasterObjectPool.h"

class BlasterFactory
{
private:
	static BlasterFactory* ptrInstance;

	static BlasterFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new BlasterFactory();
		return *ptrInstance;
	}

	BlasterFactory() = default;
	BlasterFactory(const BlasterFactory&) = delete;
	BlasterFactory& operator=(const BlasterFactory&) = delete;
	~BlasterFactory() = default;

	BlasterObjectPool blasterPool;

	Blaster* privCreateBlaster();
	void privRecycleBlaster(GameObject* b);



public:
	static Blaster* CreateBlaster() { return Instance().privCreateBlaster(); }

	static void RecycleBlaster(GameObject* b) { Instance().privRecycleBlaster(b); }

	static void Terminate();
};

#endif _BlasterFactory
