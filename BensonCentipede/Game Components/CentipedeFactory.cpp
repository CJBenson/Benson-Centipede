#include "CentipedeFactory.h"
#include "CentipedeSpawner.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"
#include "GameManager.h"

CentipedeFactory* CentipedeFactory::ptrInstance = nullptr;


CentipedeFactory::CentipedeFactory()
{
	currHeads = 0;
}


void CentipedeFactory::privCreateCentipede(int bodys, sf::Vector2i start)
{
	//Starting with head
	CentipedeHead* mainHead = centipedePool.GetCentipedeHead(start);
	mainHead->InitializeOrig(start);
	mainHead->SetExternalManagement(RecycleCentipedeHead);

	//Then bodies, if any
	if (bodys > 0) {
		CentipedeBody* currBody = centipedePool.GetCentipedeBody(start);
		currBody->Initialize(start);
		currBody->SetExternalManagement(RecycleCentipedeBody);
		mainHead->SetNext(currBody);
		currBody->SetPrev(mainHead);

		CentipedeBody* prevBody = nullptr;
		for (int i = 0; i < bodys - 1; i++)
		{
			prevBody = currBody;
			currBody = centipedePool.GetCentipedeBody(start);
			currBody->Initialize(start);
			currBody->SetExternalManagement(RecycleCentipedeBody);

			prevBody->SetNext(currBody);
			currBody->SetPrev(prevBody);
		}

		currBody->SetNext(nullptr);
	}
	currHeads += 1;
}


CentipedeHead* CentipedeFactory::privCreateFromPromotion(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame)
{
	currHeads += 1;
	CentipedeHead* newHead = new CentipedeHead(posish, gPosish, state, scaleX, scaleY, currFrame);
	newHead->InitializePromote(posish, gPosish, state, scaleX, scaleY, currFrame); //Different Init for promotion
	newHead->SetExternalManagement(RecycleCentipedeHead);

	return newHead;
}


void CentipedeFactory::privRecycleCentipedeHead(GameObject* b)
{
	centipedePool.ReturnCentipedeHead(static_cast<CentipedeHead*>(b));
}


void CentipedeFactory::privDecrementHeads() {
	currHeads -= 1;

	if (currHeads <= 0)
		GameManager::NextWave();
}


void CentipedeFactory::privRecycleCentipedeBody(GameObject* b)
{
	centipedePool.ReturnCentipedeBody(static_cast<CentipedeBody*>(b));
}


void CentipedeFactory::privCleanup()
{
	while (!activeSegments.empty())
	{
		CentipedeSegment* c = activeSegments.front();
		activeSegments.pop_front();
		c->MarkForDestroy();
	}
	currHeads = 0;
}


void CentipedeFactory::privAddToActive(CentipedeSegment* c)
{
	activeSegments.push_back(c);
}
void CentipedeFactory::privRemoveFromActive(CentipedeSegment* c)
{
	activeSegments.remove(c);
}


void CentipedeFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}