#ifndef _CmdScoreByDist
#define _CmdScoreByDist

#include "CmdScore.h"

class Spider;
class Blaster;
class CmdScoreByDist : public CmdScore
{
private:
	//float distance;

	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;

public:
	CmdScoreByDist() = default;
	CmdScoreByDist(const CmdScoreByDist& r) = delete;
	CmdScoreByDist& operator =(const CmdScoreByDist& r) = delete;
	~CmdScoreByDist() = default;

	void Initialize(int dNear, int dMed, int dFar,
				   int vNear, int vMed, int vFar, /*Spider* s, Blaster* b,*/ ScoreManager* m);

	virtual void Execute() override;
};

#endif _CmdScoreByDist