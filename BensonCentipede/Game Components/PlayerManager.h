#ifndef _PlayerManager
#define _PlayerManager

class Player;
class Blaster;
class KeyboardSystem;
class AIControl;

class PlayerManager
{
public:
	PlayerManager();
	PlayerManager(const PlayerManager& r) = delete;
	PlayerManager& operator =(const PlayerManager& r) = delete;
	~PlayerManager();

	Player* GetCurrent();
	void Swap();
	void ChangePlayers(Player* newPlayer);

	void AddScoreToCurrent(int val);
	void GetBothScores(int& s1, int& s2);
	void SetBlaster(Blaster* b);
	void PlayMode(bool tP);
	void AttractorMode();

private:
	bool twoPlayer;
	Player* currentPlayer;
	Player* P1;
	Player* P2;
	Player* AI;

	KeyboardSystem* keyboard;
	AIControl* ai;

	Blaster* myBlaster;
};

#endif _PlayerManager
