#include "CmdFactory.h"
#include "CmdScoreByVal.h"
#include "CmdScoreByDist.h"

CmdFactory* CmdFactory::ptrInstance = nullptr;

CmdScoreByVal* CmdFactory::privCreateCmdVal(int v, ScoreManager* sm)
{
	CmdScoreByVal* c = cmdPool.GetCmdVal();
	c->Initialize(v, sm);
	
	return c;
}
void CmdFactory::privRecycleCmdVal(CmdScoreByVal* s)
{
	cmdPool.ReturnCmdVal(s);
}


CmdScoreByDist* CmdFactory::privCreateCmdDist(int dNear, int dMed, int dFar,
								   int vNear, int vMed, int vFar, ScoreManager* m)
{
	CmdScoreByDist* c = cmdPool.GetCmdDist();
	c->Initialize(dNear, dMed, dFar, vNear, vMed, vFar, m);

	return c;
}
void CmdFactory::privRecycleCmdDist(CmdScoreByDist* s)
{
	cmdPool.ReturnCmdDist(s);
}

void CmdFactory::Terminate() 
{
	delete ptrInstance;
	ptrInstance = nullptr;
}