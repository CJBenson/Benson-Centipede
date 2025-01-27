#ifndef _CentipedeFactory
#define _CentipedeFactory

#include "TEAL\CommonElements.h"
#include "CentipedeSegment.h"
#include "CentipedeObjectPool.h"
#include <list>

class CentipedeSpawner;

class CentipedeFactory
{
private:
	int currHeads; //Head count for wave changing
	std::list<CentipedeSegment*> activeSegments; //Segment list for cleanup

	static CentipedeFactory* ptrInstance;

	static CentipedeFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new CentipedeFactory();
		return *ptrInstance;
	}

	CentipedeFactory();
	CentipedeFactory(const CentipedeFactory&) = delete;
	CentipedeFactory& operator=(const CentipedeFactory&) = delete;
	~CentipedeFactory() = default;

	CentipedeObjectPool centipedePool;

	void privCreateCentipede(int bodys, sf::Vector2i start); //creates the entire centipede, head & bodies
	CentipedeHead* privCreateFromPromotion(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame);

	void privRecycleCentipedeHead(GameObject* b);
	void privRecycleCentipedeBody(GameObject* b);

	void privDecrementHeads(); //For currHeads int

	void privCleanup();

	//Add & remove from cleanup list
	void privAddToActive(CentipedeSegment* c);
	void privRemoveFromActive(CentipedeSegment* c);

public:
	static void CreateCentipede(int bodySegs, sf::Vector2i start) { Instance().privCreateCentipede(bodySegs, start); }

	static CentipedeHead* CentipedePromotion(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame) 
	{
		return Instance().privCreateFromPromotion(posish, gPosish, state, scaleX, scaleY, currFrame);
	}

	static void RecycleCentipedeHead(GameObject* b) { Instance().privRecycleCentipedeHead(b); }
	static void RecycleCentipedeBody(GameObject* b) { Instance().privRecycleCentipedeBody(b); }

	static void Decrement() { Instance().privDecrementHeads(); }

	static void AddToActive(CentipedeSegment* c) { Instance().privAddToActive(c); };
	static void	RemoveFromActive(CentipedeSegment* c) { Instance().privRemoveFromActive(c); };
	static void Cleanup() { Instance().privCleanup(); }

	static void Terminate();
};

#endif _CentipedeFactory
