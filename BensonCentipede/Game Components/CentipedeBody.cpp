#include "CentipedeBody.h"
#include "CentipedeHead.h"
#include "CentipedeFactory.h"
#include "MushroomManager.h"
#include "MoveState.h"
#include "MoveFSM.h"
#include "Stationary.h"
#include "OffsetArray.h"
#include "ScoreManager.h"
#include "CmdScore.h"
#include "GameManager.h"

CentipedeBody::CentipedeBody(sf::Vector2i startingGridPos)
{
	//GameObject Initializations
	//-----------------------------------------------------------------------------
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede Body"), 8, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(-2, 2);
	MainSprite.setPosition(Pos);
	MainSprite.SetAnimation(0, 7);

	bitmap = ResourceManager::GetTextureBitmap("Centipede Body");
	SetCollider(MainSprite, bitmap, true);

	pDeath = GameManager::AccessScoreManager()->GetScoreCommand(ScoreManager::ScoreEvents::CentiBodyKilled);
}


void CentipedeBody::Initialize(sf::Vector2i startingGridPos)
{
	//CentipedeHead Initializations
	//-----------------------------------------------------------------------------
	isHead = false;

	gridPos = startingGridPos;

	pCurrState = &MoveFSM::StateStationary;

	Pos = sf::Vector2f(((float)MushroomManager::CELL_SIZE * (gridPos.x + 0.5f)), ((float)MushroomManager::CELL_SIZE * (gridPos.y + 0.5f)));
	Displacement = sf::Vector2f(0, 0);
	MainSprite.setPosition(Pos);

	pDeath->SetManager(GameManager::AccessScoreManager());

	CentipedeFactory::AddToActive(this);

	RegisterCollision<CentipedeBody>(*this);
}


void CentipedeBody::Update()
{
	Displacement = pCurrState->GetMoveOffsets()->offsets[framesPassed - 1]; //Take offset array from current state
	Pos += Displacement;

	MainSprite.setPosition(Pos);
	MainSprite.Update();

	if (framesPassed == (MushroomManager::CELL_SIZE / 2)) {
		framesPassed = 0;
	}

	framesPassed++;
}
void CentipedeBody::Draw()
{
	WindowManager::Window().draw(MainSprite);
}


void CentipedeBody::Collision(Bullet* other)
{
	Die();
}


void CentipedeBody::Die()
{
	//State has a Grid Offset value to update the grid position and figure out where to spawn mushroom
	int xAmt = pCurrState->GetGridOffset().x;
	if (Displacement.y == 0)
		MushroomManager::AddShroom(gridPos.x + xAmt, gridPos.y);

	if (next != nullptr)
		next->Promote();

	CentipedeFactory::RemoveFromActive(this);

	GameManager::AccessScoreManager()->SendScoreCmd(pDeath);

	MarkForDestroy();
}


void CentipedeBody::Destroy()
{
	if (next != nullptr)
		next->SetPrev(nullptr);
	if (prev != nullptr)
		prev->SetNext(nullptr);

	next = nullptr;
	prev = nullptr;

	DeregisterCollision<CentipedeBody>(*this);
}