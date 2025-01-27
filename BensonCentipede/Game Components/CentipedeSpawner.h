#ifndef _CentipedeSpawner
#define _CentipedeSpawner

#include "TEAL\CommonElements.h"
#include <list>

class CentipedeSegment;
class CentipedeSpawner : public GameObject
{
public:
	CentipedeSpawner();
	CentipedeSpawner(const CentipedeSpawner& r) = delete;
	CentipedeSpawner& operator =(const CentipedeSpawner& r) = delete;
	~CentipedeSpawner() = default;

	void WaveValues(int sH, int bS, float s);

	void SpawnCentipede();

private:
	int soloHeads;
	int bodySegments;
	float speed;

	const sf::Vector2i startingGridPos = sf::Vector2i(15, 0);
};

#endif _CentipedeSpawner
