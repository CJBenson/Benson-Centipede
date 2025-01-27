#include "ScorpionSpawner.h"
#include "ScorpionFactory.h"

ScorpionSpawner::ScorpionSpawner()
{
	active = false;
	frequency = 10.0f;

	RegisterInput(InputFlags::KeyPressed);
}

void ScorpionSpawner::WaveValues(bool a, float f)
{
	active = a;
	frequency = f;

	if (active)
		SetAlarm(0, frequency);
}

void ScorpionSpawner::SpawnScorpion()
{
	ScorpionFactory::CreateScorpion(rand() % LOWER_LIMIT);
}

void ScorpionSpawner::Alarm0() {
	SpawnScorpion();
	SetAlarm(0, frequency);
}

void ScorpionSpawner::Destroy()
{
	AlarmCancel(0);
	DeregisterInput();
}
void ScorpionSpawner::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::D)
		SpawnScorpion();
}