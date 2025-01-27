#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "CentipedeFactory.h"
#include "MushroomManager.h"
#include "Bullet.h"
#include "MoveFSM.h"
#include "TurnDownRight.h"
#include "TurnDownLeft.h"
#include "TurnUpLeft.h"
#include "TurnUpRight.h"
#include "MoveRightDown.h"
#include "OffsetArray.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "GameManager.h"

CentipedeHead::CentipedeHead(sf::Vector2i startingGridPos)
{
	//GameObject Initializations
	//-----------------------------------------------------------------------------
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede Head"), 8, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(-2, 2);
	MainSprite.setPosition(Pos);
	MainSprite.SetAnimation(0, 7);

	bitmap = ResourceManager::GetTextureBitmap("Centipede Head");
	SetCollider(MainSprite, bitmap, true);

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::CentiHeadKilled);
}

CentipedeHead::CentipedeHead(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame)
{
	//Constructor specifically for promotion
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede Head"), 8, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(scaleX, scaleY);
	MainSprite.setPosition(Pos);
	MainSprite.SetAnimation(0, 7);

	bitmap = ResourceManager::GetTextureBitmap("Centipede Head");
	SetCollider(MainSprite, bitmap, true);

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::CentiHeadKilled);
}

void CentipedeHead::InitializeOrig(sf::Vector2i startingGridPos)
{
	//for original centipede spawn
	pCurrState = &MoveFSM::StateTurnDownRight;

	framesPassed = 1;

	gridPos = startingGridPos;

	poisoned = false;

	Pos = sf::Vector2f(((float)MushroomManager::CELL_SIZE * (gridPos.x + 0.5f)), ((float)MushroomManager::CELL_SIZE * (gridPos.y + 0.5f)));
	Displacement = sf::Vector2f(0, 0);
	MainSprite.setPosition(Pos);

	CentipedeFactory::AddToActive(this);

	pDeath->SetManager(GameManager::AccessScoreManager());

	RegisterCollision<CentipedeHead>(*this);
}
void CentipedeHead::InitializePromote(sf::Vector2f posish, sf::Vector2i gPosish, const MoveState* state, float scaleX, float scaleY, int currFrame)
{
	//for promotion
	Pos = posish;
	gridPos = gPosish;

	framesPassed = currFrame;

	pCurrState = state;

	poisoned = false;

	Displacement = pCurrState->GetMoveOffsets()->offsets[framesPassed - 1];
	MainSprite.setPosition(Pos);

	CentipedeFactory::AddToActive(this);

	pDeath->SetManager(GameManager::AccessScoreManager());

	RegisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::Update()
{
	//For changing the sprite's scale for turning
	float prevXScale;
	float prevYScale;

	Displacement = (pCurrState->GetMoveOffsets())->offsets[framesPassed - 1];

	Pos += Displacement;

	MainSprite.setPosition(Pos);
	MainSprite.Update();

	//every 8 frames it changes state based on environment
	if (framesPassed == (MushroomManager::CELL_SIZE / 2)) {
		framesPassed = 0;
		UpdateGridPos(pCurrState->GetGridOffset());
		ChangeState();
		std::string printStatement = "X: " + std::to_string(gridPos.x) + ", Y: " + std::to_string(gridPos.y);
	}
	//if it's halfway through turning it flips scale
	if (framesPassed == (MushroomManager::CELL_SIZE / 4) && Displacement.y != 0) {
		prevXScale = MainSprite.getScale().x;
		prevYScale = MainSprite.getScale().y;

		MainSprite.setScale(-prevXScale, prevYScale);
		if (next != nullptr)
			next->ScaleSprite(prevXScale, prevYScale);
	}

	framesPassed += 1;
}
void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}


void CentipedeHead::ChangeState()
{
	//pass down the line
	if (this->next != nullptr) {
		next->SetState(pCurrState);
	}

	pCurrState = pCurrState->GetNextState(this);

	//uses offset array to find out if it's moving horizontally or vertically
	if (pCurrState->GetMoveOffsets()->offsets[0].y != 0)
		MainSprite.SetAnimation(10, 15);
	else
		MainSprite.SetAnimation(0, 7);
}


void CentipedeHead::SetPoison(bool newPoison)
{
	poisoned = newPoison;
}
bool CentipedeHead::GetPoison()
{
	return poisoned;
}


void CentipedeHead::Collision(Bullet* other)
{
	Die();
}


void CentipedeHead::Die()
{
	int xAmt = pCurrState->GetGridOffset().x;
	if (Displacement.y == 0)
		MushroomManager::AddShroom(gridPos.x + xAmt, gridPos.y);

	if (next != nullptr)
		next->Promote();

	CentipedeFactory::Decrement();
	CentipedeFactory::RemoveFromActive(this);

	GameManager::AccessScoreManager()->SendScoreCmd(pDeath);

	MarkForDestroy();
}


void CentipedeHead::Destroy()
{
	if (next != nullptr)
		next->SetPrev(nullptr);
	if (prev != nullptr)
		prev->SetNext(nullptr);

	next = nullptr;
	prev = nullptr;

	DeregisterCollision<CentipedeHead>(*this);
}