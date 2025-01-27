#include "KeyboardSystem.h"
#include "InputSystem.h"
#include "Blaster.h"

KeyboardSystem::KeyboardSystem(Blaster* b) {
	RegisterInput(InputFlags::KeyPressed);
	blaster = b;
	blasterSpeed = 6;
}

void KeyboardSystem::Update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		MoveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		MoveDown();
	}
}

void KeyboardSystem::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (k == sf::Keyboard::S) {
		FireBlaster();
	}
}