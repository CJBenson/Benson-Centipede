#include "CentipedeSpawner.h"
#include "CentipedeFactory.h"

CentipedeSpawner::CentipedeSpawner()
{
	soloHeads = 0;
	bodySegments = 11;
	speed = 2;
}

void CentipedeSpawner::WaveValues(int sH, int bS, float s)
{
	soloHeads = sH;
	bodySegments = bS;
	speed = s;
}

void CentipedeSpawner::SpawnCentipede()
{
	CentipedeFactory::CreateCentipede(bodySegments, startingGridPos);

	//Loops through creating 0-body centipedes
	for (int i = 0; i < soloHeads; i++) 
	{
		int randomX = rand() % 30;
		CentipedeFactory::CreateCentipede(0, sf::Vector2i(randomX, startingGridPos.y));
	}
}