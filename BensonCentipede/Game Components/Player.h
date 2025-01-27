#ifndef _Player
#define _Player

class InputSystem;
class Blaster;
class MushroomGrid;

class Player
{
public:
	Player();
	Player(const Player& r) = delete;
	Player& operator =(const Player& r) = delete;
	~Player();
	
	void AddScore(int amt);
	int GetScore();

	void SetBlaster(Blaster* b);

	void SetLives(int l);
	int GetLives();

	int GetWave();
	void SetWave(int newWave);

	MushroomGrid* GetGrid();

	void SetControlStrategy(InputSystem* cs);

	void Die();

private:
	int currWave;
	int currScore;
	int livesLeft;
	const int START_LIVES = 3;

	InputSystem* controlStrategy;
	Blaster* myBlaster;
	MushroomGrid* myGrid;
};


#endif _Player
