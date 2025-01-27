#ifndef _ScoreManager
#define _ScoreManager

#include "TEAL\CommonElements.h"
#include <queue>

class CmdScore;
class CmdScoreByVal;
class CmdScoreByDist;
class PlayerManager;
class HUDManager;

class ScoreManager: public GameObject
{
public:
	ScoreManager(PlayerManager* pm);
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
	~ScoreManager();

	enum class ScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, SpiderKilled, CentiBodyKilled, CentiHeadKilled, MushroomRegen };

	void AddScore(int val);

	CmdScore* GetScoreCommand(ScoreEvents ev);

	virtual void Update();

	void SendScoreCmd(CmdScore* c);
	void ProcessScores();

private:
	//Score Values
	static const int FleaDeath = 200;
	static const int ScorpionDeath = 1000;
	static const int MushroomDeath = 1;

	static const int SpiderDeath = 600;

	static const int CentiBodyDeath = 10;
	static const int CentiHeadDeath = 100;

	static const int MushroomRegen = 5;

	std::queue<CmdScore*> CmdQueue;
	std::queue<CmdScoreByVal*> AllValCmds;
	std::queue<CmdScoreByDist*> AllDistCmds;

	PlayerManager* playerManager;
};

#endif _ScoreManager