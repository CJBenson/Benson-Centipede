#include "CmdScoreByDist.h"
#include "ScoreManager.h"
#include "Spider.h"
#include "Blaster.h"

void CmdScoreByDist::Initialize(int dNear, int dMed, int dFar,
							   int vNear, int vMed, int vFar, /*Spider* s, Blaster* b,*/ ScoreManager* m)
{
	manager = m;
	this->dNear = dNear;
	this->dMed = dMed;
	this->dFar = dFar;
	this->vNear = vNear;
	this->vMed = vMed;
	this->vFar = vFar;

	//distance = b->GetPos().y - s->GetPos().y;
}

void CmdScoreByDist::Execute()
{
	//ScoreManager::AddScore();
}