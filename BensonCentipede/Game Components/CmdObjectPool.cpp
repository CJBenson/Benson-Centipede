#include "CmdScore.h"
#include "CmdScoreByVal.h"
#include "CmdScoreByDist.h"
#include "CmdObjectPool.h"

CmdObjectPool::~CmdObjectPool()
{
	while (!recycledVals.empty())
	{
		delete recycledVals.top();
		recycledVals.pop();
	}
	while (!recycledDists.empty())
	{
		delete recycledDists.top();
		recycledDists.pop();
	}
}

CmdScoreByVal* CmdObjectPool::GetCmdVal()
{
	CmdScoreByVal* c;

	if (recycledVals.empty())
	{
		c = new CmdScoreByVal();
	}
	else
	{
		c = recycledVals.top();
		recycledVals.pop();
	}

	return c;
}
CmdScoreByDist* CmdObjectPool::GetCmdDist()
{
	CmdScoreByDist* c;

	if (recycledDists.empty())
		c = new CmdScoreByDist();
	else 
	{
		c = recycledDists.top();
		recycledDists.pop();
	}

	return c;
}


void CmdObjectPool::ReturnCmdVal(CmdScoreByVal* b)
{
	recycledVals.push(b);
}
void CmdObjectPool::ReturnCmdDist(CmdScoreByDist* b)
{
	recycledDists.push(b);
}