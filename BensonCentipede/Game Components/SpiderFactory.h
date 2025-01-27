#ifndef _SpiderFactory
#define _SpiderFactory

#include "TEAL\CommonElements.h"
#include "SpiderObjectPool.h"
#include <list>

class SpiderFactory
{
private:
	static SpiderFactory* ptrInstance;
	std::list<Spider*> activeSpiders;

	static SpiderFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new SpiderFactory();
		return *ptrInstance;
	}

	SpiderFactory() = default;
	SpiderFactory(const SpiderFactory&) = delete;
	SpiderFactory& operator=(const SpiderFactory&) = delete;
	~SpiderFactory() = default;

	SpiderObjectPool spiderPool;

	void privCreateSpider();
	void privRecycleSpider(GameObject* b);

	void privCleanup();
	void privAddToActive(Spider* s);
	void privRemoveFromActive(Spider* s);

public:
	static void CreateSpider() { Instance().privCreateSpider(); }
	static void RecycleSpider(GameObject* b) { Instance().privRecycleSpider(b); }

	static void Cleanup() { Instance().privCleanup(); };
	static void AddToActive(Spider* s) { Instance().privAddToActive(s); };
	static void RemoveFromActive(Spider* s) { Instance().privRemoveFromActive(s); };

	static void Terminate();
};

#endif _SpiderFactory