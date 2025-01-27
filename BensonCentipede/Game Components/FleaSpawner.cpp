#include "FleaSpawner.h"
#include "Flea.h"
#include "MushroomManager.h"
#include "FleaFactory.h"

FleaSpawner::FleaSpawner()
{
	active = false;
	minShrooms = 3;

	fleaPresent = false;

	MushroomManager::SetFleaSpawner(this);
	RegisterInput(InputFlags::KeyPressed);
	SetUpdateOrder(1);
}

void FleaSpawner::WaveValues(bool a, int m)
{
	active = a;
	minShrooms = m;
}

void FleaSpawner::CheckShrooms()
{
	//Called every time a mushroom is removed
	if (active && MushroomManager::ShroomsInPA() <= minShrooms)
		SpawnFlea();
}

void FleaSpawner::Destroy()
{
	AlarmCancel(0);
	DeregisterInput();
}

void FleaSpawner::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::F) {
		SpawnFlea();
	}
}

void FleaSpawner::Alarm0()
{
	fleaPresent = false;
}

void FleaSpawner::SpawnFlea()
{
	//only one flea at a time
	if (!fleaPresent) {
		FleaFactory::CreateFlea((rand() % MushroomManager::GRID_H)); //randomized column to descend
		fleaPresent = true;
		SetAlarm(0, fleaTime);
	}
}