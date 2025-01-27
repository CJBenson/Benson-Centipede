#include "ScorpionObjectPool.h"
#include "Scorpion.h"

ScorpionObjectPool::ScorpionObjectPool(){}

ScorpionObjectPool::~ScorpionObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Scorpion* ScorpionObjectPool::GetScorpion()
{
	Scorpion* s;

	if (recycledItems.empty())
	{
		s = new Scorpion();
	}
	else
	{
		s = recycledItems.top();
		recycledItems.pop();

		s->RegisterToCurrentScene();
	}

	return s;
}

void ScorpionObjectPool::ReturnScorpion(Scorpion* b) 
{
	recycledItems.push(static_cast<Scorpion*>(b));
}