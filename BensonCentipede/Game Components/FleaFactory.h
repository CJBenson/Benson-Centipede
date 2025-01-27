#ifndef _FleaFactory
#define _FleaFactory

#include "TEAL\CommonElements.h"
#include "FleaObjectPool.h"
#include <list>

class MushroomManager;

class FleaFactory
{
private:
	static FleaFactory* ptrInstance;
	std::list<Flea*> activeFleas;

	static FleaFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new FleaFactory();
		return *ptrInstance;
	}

	FleaFactory() = default;
	FleaFactory(const FleaFactory&) = delete;
	FleaFactory& operator=(const FleaFactory&) = delete;
	~FleaFactory() = default;

	FleaObjectPool fleaPool;

	void privCreateFlea(int xPos);
	void privRecycleFlea(GameObject* b);

	void privCleanup();
	void privAddToActive(Flea* f);
	void privRemoveFromActive(Flea* f);

public:
	static void CreateFlea(int xPos) { Instance().privCreateFlea(xPos); }
	static void RecycleFlea(GameObject* b) { Instance().privRecycleFlea(b); }

	static void Cleanup() { Instance().privCleanup(); };
	static void AddToActive(Flea* f) { Instance().privAddToActive(f); };
	static void RemoveFromActive(Flea* f) { Instance().privRemoveFromActive(f); };

	static void Terminate();
};

#endif _FleaFactory