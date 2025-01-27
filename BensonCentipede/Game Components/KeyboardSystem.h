#ifndef _KeyboardSystem
#define _KeyboardSystem

#include "TEAL/CommonElements.h"
#include "InputSystem.h"

class Blaster;

class KeyboardSystem : public InputSystem
{
public:
	KeyboardSystem(Blaster* b);

	KeyboardSystem() = delete;
	KeyboardSystem(const KeyboardSystem& r) = delete;
	KeyboardSystem& operator=(const KeyboardSystem& r) = delete;
	~KeyboardSystem() = default;

	virtual void Update();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};

#endif _KeyboardSystem
