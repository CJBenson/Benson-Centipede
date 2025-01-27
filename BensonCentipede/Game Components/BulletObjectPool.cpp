
#include "BulletObjectPool.h"
#include "TEAL\CommonElements.h"
#include "Bullet.h"

BulletObjectPool::BulletObjectPool()
{
}

BulletObjectPool::~BulletObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletObjectPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();


		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletObjectPool::ReturnBullet(Bullet* b)
{
	recycledItems.push(static_cast<Bullet*>(b));

}