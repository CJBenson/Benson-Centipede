#include "CentipedeObjectPool.h"
#include "CentipedeSegment.h"
#include "CentipedeHead.h"
#include "CentipedeBody.h"

CentipedeObjectPool::~CentipedeObjectPool()
{
	while (!recycledHeads.empty())
	{
		delete recycledHeads.top();
		recycledHeads.pop();
	}

	while (!recycledBodies.empty())
	{
		delete recycledBodies.top();
		recycledBodies.pop();
	}
}

CentipedeHead* CentipedeObjectPool::GetCentipedeHead(sf::Vector2i start)
{
	CentipedeHead* chead;

	if (recycledHeads.empty())
	{
		chead = new CentipedeHead(start);
	}
	else
	{
		chead = recycledHeads.top();
		recycledHeads.pop();

		chead->RegisterToCurrentScene();
	}

	return chead;
}

CentipedeBody* CentipedeObjectPool::GetCentipedeBody(sf::Vector2i start)
{
	CentipedeBody* cbody;

	if (recycledBodies.empty())
	{
		cbody = new CentipedeBody(start);
	}
	else
	{
		cbody = recycledBodies.top();
		recycledBodies.pop();

		cbody->RegisterToCurrentScene();
	}

	return cbody;
}

void CentipedeObjectPool::ReturnCentipedeHead(CentipedeHead* b)
{
	recycledHeads.push(static_cast<CentipedeHead*>(b));
}

void CentipedeObjectPool::ReturnCentipedeBody(CentipedeBody* b)
{
	recycledBodies.push(static_cast<CentipedeBody*>(b));
}