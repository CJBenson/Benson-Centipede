#include "BlasterFactory.h"
#include "MushroomManager.h"
#include "BlasterObjectPool.h"
#include "Blaster.h"

BlasterFactory* BlasterFactory::ptrInstance = nullptr;


Blaster* BlasterFactory::privCreateBlaster()
{
	Blaster* f = blasterPool.GetBlaster();

	f->SetExternalManagement(RecycleBlaster);

	f->Initialize();

	return f;
}

void BlasterFactory::privRecycleBlaster(GameObject* b)
{
	blasterPool.ReturnBlaster(static_cast<Blaster*>(b));
}

void BlasterFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}