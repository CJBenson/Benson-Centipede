#ifndef _ScorpionSpawner
#define _ScorpionSpawner

#include "TEAL\CommonElements.h"

class ScorpionSpawner : public GameObject
{
public:
	ScorpionSpawner();
	ScorpionSpawner(const ScorpionSpawner& r) = delete;
	ScorpionSpawner& operator=(const ScorpionSpawner& r) = delete;
	~ScorpionSpawner() = default;

	void WaveValues(bool a, float f);

	void SpawnScorpion();

	virtual void Alarm0();

	virtual void Destroy();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

private:
	const int LOWER_LIMIT = 25;

	bool active;
	float frequency;
};
#endif _ScorpionSpawner
