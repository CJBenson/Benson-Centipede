#ifndef _GameEntityManager
#define _GameEntityManager

class CentipedeSpawner;
class FleaSpawner;
class MushroomManager;
class ScorpionSpawner;
class SpiderSpawner;
class BlasterSpawner;
struct Wave;

class GameEntityManager
{
public:
	GameEntityManager();
	GameEntityManager(const GameEntityManager& r) = delete;
	GameEntityManager& operator =(const GameEntityManager& r) = delete;
	~GameEntityManager() = default;

	void CreateNewSpawners();

	void SwitchWaveData(Wave newData);
	void CritterCleanup();

	void RespawnBlaster();

private:
	CentipedeSpawner* centipedeSpawner;
	FleaSpawner* fleaSpawner;
	ScorpionSpawner* scorpionSpawner;
	SpiderSpawner* spiderSpawner;
	BlasterSpawner* blasterSpawner;
};

#endif _GameEntityManager
