#ifndef _GameManager
#define _GameManager

class WaveManager;
class PlayerManager;
class ScoreManager;
class GameEntityManager;
class HUDManager;
class Blaster;

class GameManager
{
public:
	static void NextWave() { Instance().privNextWave(); };
	static void ResetWave() { Instance().privResetWave(); };

	static ScoreManager* AccessScoreManager() {	return Instance().scoreManager; };
	static HUDManager* AccessHudManager() { return Instance().hudManager; };

	static void StartPlayMode(bool tP) { Instance().privStartPlay(tP); };
	static void InitializePlayMode() { Instance().privInitPlay(); };
	static void StartAttractorMode() { Instance().privStartAttractor(); }
	static void InitializeAttractorMode() { Instance().privInitAttract(); };

	static void BlasterDeath() { Instance().privDeath(); };
	static void SetBlaster(Blaster* b) { Instance().privSetBlaster(b); };

	static void CritterCleanup() { Instance().privCritterCleanup(); };

	static void Terminate();

private:
	static GameManager* ptrInstance;

	//Waves
	void privNextWave();
	void privResetWave();
	void privActivateWave(int waveNum);

	//Game Start/End
	void privStartPlay(bool tP);
	void privInitPlay();
	void privStartAttractor();
	void privInitAttract();

	//Blaster
	void privDeath();
	void privSetBlaster(Blaster* b);

	//Cleanup
	void privCritterCleanup();

	GameManager();
	GameManager(const GameManager& r) = delete;
	GameManager& operator =(const GameManager& r) = delete;
	~GameManager();

	static GameManager& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new GameManager();
		return *ptrInstance;
	};

	//class data
	WaveManager* waveManager;
	PlayerManager* playerManager;
	ScoreManager* scoreManager;
	GameEntityManager* entityManager;
	HUDManager* hudManager;
	Blaster* blaster;

	bool twoPlayer;
};

#endif _GameManager
