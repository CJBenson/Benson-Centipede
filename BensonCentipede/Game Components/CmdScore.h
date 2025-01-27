#ifndef _CmdScore
#define _CmdScore

class ScoreManager;
class CmdScore
{
public:
	CmdScore() = default;
	CmdScore(const CmdScore& r) = delete;
	CmdScore& operator =(const CmdScore& r) = delete;
	virtual ~CmdScore() = default;

	virtual void Execute() = 0;

	void SetManager(ScoreManager* sm) { manager = sm; };

protected:
	ScoreManager* manager;
};

#endif _CmdScore
