#ifndef _CmdFactory
#define _CmdFactory

#include "CmdScore.h"
#include "CmdObjectPool.h"

class ScoreManager;

class CmdFactory
{
private:
	static CmdFactory* ptrInstance;

	static CmdFactory& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new CmdFactory();
		return *ptrInstance;
	}

	CmdFactory() = default;
	CmdFactory(const CmdFactory& r) = delete;
	CmdFactory& operator =(const CmdFactory& r) = delete;
	~CmdFactory() = default;

	CmdObjectPool cmdPool;

	CmdScoreByVal* privCreateCmdVal(int v, ScoreManager* sm);
	void privRecycleCmdVal(CmdScoreByVal* s);

	CmdScoreByDist* privCreateCmdDist(int dNear, int dMed, int dFar,
						  int vNear, int vMed, int vFar, ScoreManager* m);
	void privRecycleCmdDist(CmdScoreByDist* s);

public:
	static CmdScoreByVal* CreateCmdVal(int v, ScoreManager* sm) { return Instance().privCreateCmdVal(v, sm); }
	static void RecycleCmdVal(CmdScoreByVal* b) { Instance().privRecycleCmdVal(b); }

	static CmdScoreByDist* CreateCmdDist(int dNear, int dMed, int dFar,
							  int vNear, int vMed, int vFar, ScoreManager* m)
	{ return Instance().privCreateCmdDist(dNear, dMed, dFar, vNear, vMed, vFar, m); }
	static void RecycleCmdDist(CmdScoreByDist* b) { Instance().privRecycleCmdDist(b); }

	static void Terminate();
};

#endif _CmdFactory