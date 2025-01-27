#ifndef _CmdScoreByVal
#define _CmdScoreByVal

#include "CmdScore.h"

class CmdScoreByVal : public CmdScore
{
private:
	int score;

public:
	CmdScoreByVal() = default;
	CmdScoreByVal(const CmdScoreByVal& r) = delete;
	CmdScoreByVal& operator =(const CmdScoreByVal& r) = delete;
	~CmdScoreByVal() = default;

	void Initialize(int val, ScoreManager* m);

	virtual void Execute() override;
};

#endif _CmdScoreByVal
