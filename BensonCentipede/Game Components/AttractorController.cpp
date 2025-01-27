#include "AttractorController.h"
#include "GameManager.h"

AttractorController::AttractorController()
{
	RegisterInput(InputFlags::KeyPressed);
}

void AttractorController::Destroy()
{
	DeregisterInput();
}
void AttractorController::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if(k == sf::Keyboard::Num1)
		GameManager::StartPlayMode(false);
	else if (k == sf::Keyboard::Num2)
		GameManager::StartPlayMode(true);
}