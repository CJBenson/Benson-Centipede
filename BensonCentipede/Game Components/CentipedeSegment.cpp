#include "CentipedeSegment.h"
#include "CentipedeHead.h"
#include "CentipedeFactory.h"
#include "MoveState.h"

CentipedeSegment::CentipedeSegment()
{
	framesPassed = 1;
	isHead = false;
	pCurrState = nullptr;
}

sf::Vector2f CentipedeSegment::GetPosition()
{
	return Pos;
}
void CentipedeSegment::UpdateGridPos(sf::Vector2i add)
{
	gridPos += add;
}
sf::Vector2i CentipedeSegment::GetGridPos()
{
	return gridPos;
}

void CentipedeSegment::SetState(const MoveState* newState)
{
	if (next != nullptr) {
		next->SetState(pCurrState);
	}
	this->UpdateGridPos(pCurrState->GetGridOffset());
	pCurrState = newState;
}

void CentipedeSegment::ScaleSprite(float xScale, float yScale)
{
	MainSprite.setScale(xScale, yScale);
}

void CentipedeSegment::Promote()
{
	CentipedeHead* newHead = CentipedeFactory::CentipedePromotion(Pos, gridPos, pCurrState, MainSprite.getScale().x, MainSprite.getScale().y, framesPassed);
	newHead->SetNext(this->next);
	newHead->SetPrev(nullptr);

	if (newHead->GetNext() != nullptr) {
		newHead->GetNext()->SetPrev(newHead);
		this->next = nullptr;
		this->prev = nullptr;
	}

	CentipedeFactory::RemoveFromActive(this);

	MarkForDestroy();
}

void CentipedeSegment::SetNext(CentipedeSegment* newNext)
{
	next = newNext;
}
void CentipedeSegment::SetPrev(CentipedeSegment* newPrev)
{
	prev = newPrev;
}

CentipedeSegment* CentipedeSegment::GetNext()
{
	return next;
}
CentipedeSegment* CentipedeSegment::GetPrev()
{
	return prev;
}