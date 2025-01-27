#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "TEAL/CommonElements.h"
#include "ScorpionObjectPool.h"
#include <list>

class ScorpionFactory
{
private:
	static ScorpionFactory* ptrInstance;
	std::list<Scorpion*> activeScorps;

	static ScorpionFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new ScorpionFactory();
		return *ptrInstance;
	}

	ScorpionFactory() = default;
	ScorpionFactory(const ScorpionFactory&) = delete;
	ScorpionFactory& operator=(const ScorpionFactory&) = delete;
	~ScorpionFactory() = default;

	ScorpionObjectPool scorpionPool;

	void privCreateScorpion(int yPos);
	void privRecycleScorpion(GameObject* s);

	void privCleanup();
	void privAddToActive(Scorpion* s);
	void privRemoveFromActive(Scorpion* s);

public:
	static void CreateScorpion(int yPos) { Instance().privCreateScorpion(yPos); }
	static void RecycleScorpion(GameObject* b) { Instance().privRecycleScorpion(b); }

	static void Cleanup() { Instance().privCleanup(); };
	static void AddToActive(Scorpion* s) { Instance().privAddToActive(s); };
	static void RemoveFromActive(Scorpion* s) { Instance().privRemoveFromActive(s); };

	static void Terminate();
};

#endif _ScorpionFactory