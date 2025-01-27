#ifndef _BulletFactory
#define _BulletFactory

#include "TEAL\CommonElements.h"
#include "BulletObjectPool.h"

class Blaster;

class BulletFactory
{
private:
	static BulletFactory* ptrInstance;

	BulletObjectPool bulletPool;

	bool bulletOnScreen;

	BulletFactory();
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory() = default;

	static BulletFactory& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new BulletFactory();
		return *ptrInstance;
	};

	void privCreateBullet(Blaster* blast);
	void privRecycleBullet(GameObject* b);

public:

	static void CreateBullet(Blaster* b) { Instance().privCreateBullet(b); }

	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); }

	static void Terminate();

	static void SetBulletOnScreen(bool bOs) { Instance().bulletOnScreen = bOs; }
};

#endif _BulletFactory