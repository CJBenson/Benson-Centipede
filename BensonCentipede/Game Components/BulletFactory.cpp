#include "TEAL\CommonElements.h"
#include "BulletFactory.h"
#include "BulletObjectPool.h"
#include "Bullet.h"
#include "Blaster.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

BulletFactory::BulletFactory() {
	bulletOnScreen = false;
}

void  BulletFactory::privCreateBullet(Blaster* blast)
{
	if (!bulletOnScreen) {
		Bullet* b = bulletPool.GetBullet();

		b->SetExternalManagement(RecycleBullet);

		b->Initialize(blast);
	}
}
void BulletFactory::privRecycleBullet(GameObject* b)
{
	bulletPool.ReturnBullet(static_cast<Bullet*>(b));
}

void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}