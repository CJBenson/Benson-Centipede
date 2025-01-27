#ifndef _FleaSpawner
#define _FleaSpawner

#include "TEAL\CommonElements.h"


class FleaSpawner : public GameObject
{
public:
	FleaSpawner();
	FleaSpawner(const FleaSpawner& r) = delete;
	FleaSpawner& operator=(const FleaSpawner& r) = delete;
	~FleaSpawner() = default;

	void WaveValues(bool a, int m);

	void CheckShrooms();
	void SpawnFlea();

	virtual void Alarm0();

	virtual void Destroy();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);

private:
	bool active;
	int minShrooms;

	bool fleaPresent;
	const float fleaTime = 2.5f;
};

#endif _FleaSpawner
