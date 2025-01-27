#include "CmdScoreByVal.h"
#include "ScoreManager.h"
#include "GameManager.h"


void CmdScoreByVal::Initialize(int val, ScoreManager* m)
{
	score = val;
	manager = m;
}

void CmdScoreByVal::Execute()
{
	manager->AddScore(score);
}