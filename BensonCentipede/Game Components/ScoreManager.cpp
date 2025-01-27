#include "ScoreManager.h"
#include "CmdScore.h"
#include "CmdFactory.h"
#include "CmdScoreByVal.h"
#include "CmdScoreByDist.h"
#include "PlayerManager.h"
#include "HUDManager.h"
#include "Player.h"

ScoreManager::ScoreManager(PlayerManager* pm)
{
	playerManager = pm;
}


void ScoreManager::Update()
{
	ProcessScores();
}


void ScoreManager::AddScore(int val)
{
	playerManager->AddScoreToCurrent(val);
}

CmdScore* ScoreManager::GetScoreCommand(ScoreEvents ev)
{
	CmdScoreByVal* pCmd = nullptr;

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = CmdFactory::CreateCmdVal(FleaDeath, this);
		AllValCmds.push(pCmd);
		break;
	case ScoreEvents::ScorpionKilled:
		pCmd = CmdFactory::CreateCmdVal(ScorpionDeath, this);
		AllValCmds.push(pCmd);
		break;
	case ScoreEvents::MushroomKilled:
		pCmd = CmdFactory::CreateCmdVal(MushroomDeath, this);
		AllValCmds.push(pCmd);
		break;
	case ScoreEvents::SpiderKilled:
		pCmd = CmdFactory::CreateCmdVal(SpiderDeath, this);
		AllValCmds.push(pCmd);
		break;
	case ScoreEvents::CentiBodyKilled:
		pCmd = CmdFactory::CreateCmdVal(CentiBodyDeath, this);
		AllValCmds.push(pCmd);
		break;
	case ScoreEvents::CentiHeadKilled:
		pCmd = CmdFactory::CreateCmdVal(CentiHeadDeath, this);
		AllValCmds.push(pCmd);
		break;
	case ScoreEvents::MushroomRegen:
		pCmd = CmdFactory::CreateCmdVal(MushroomRegen, this);
		AllValCmds.push(pCmd);
		break;
	default:
		break;
	}

	return pCmd;
}

void ScoreManager::SendScoreCmd(CmdScore* c)
{
	CmdQueue.push(c);
}

void ScoreManager::ProcessScores()
{
	CmdScore* c;

	while (!CmdQueue.empty())
	{
		c = CmdQueue.front();
		c->Execute();

		CmdQueue.pop();
	}
}

ScoreManager::~ScoreManager()
{
	CmdScoreByVal* v;
	
	while (!AllValCmds.empty())
	{
		v = AllValCmds.front();
		CmdFactory::RecycleCmdVal(v);
	
		AllValCmds.pop();
	}

	CmdScoreByDist* d;

	while (!AllDistCmds.empty())
	{
		d = AllDistCmds.front();
		CmdFactory::RecycleCmdDist(d);

		AllDistCmds.pop();
	}
}