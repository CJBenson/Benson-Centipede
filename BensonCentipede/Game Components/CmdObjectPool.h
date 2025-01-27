#ifndef _CmdObjectPool
#define _CmdObjectPool

#include <stack>

class CmdScore;
class CmdScoreByVal;
class CmdScoreByDist;
class ScoreManager;

class CmdObjectPool
{
private:
	std::stack<CmdScoreByVal*> recycledVals;
	std::stack<CmdScoreByDist*> recycledDists;

public:
	CmdObjectPool() = default;
	CmdObjectPool(const CmdObjectPool&) = delete;
	CmdObjectPool& operator=(const CmdObjectPool&) = delete;
	~CmdObjectPool();

	CmdScoreByVal* GetCmdVal();
	CmdScoreByDist* GetCmdDist();


	void ReturnCmdVal(CmdScoreByVal* b);
	void ReturnCmdDist(CmdScoreByDist* b);
};

#endif _CmdObjectPool