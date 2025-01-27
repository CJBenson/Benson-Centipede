#include "InputSystem.h"
#include "Blaster.h"

InputSystem::InputSystem() {
	blaster = nullptr;
	blasterSpeed = 6;
}

void InputSystem::MoveUp()
{
	if(blaster != nullptr)
		blaster->Up();
}
void InputSystem::MoveDown()
{
	if (blaster != nullptr)
		blaster->Down();
}
void InputSystem::MoveLeft()
{
	if (blaster != nullptr)
		blaster->Left();
}
void InputSystem::MoveRight()
{
	if (blaster != nullptr)
		blaster->Right();
}
void InputSystem::FireBlaster()
{
	if (blaster != nullptr)
		blaster->Fire();
}

void InputSystem::SetBlaster(Blaster* newB)
{
	blaster = newB;

	if(blaster != nullptr)
		blaster->SetSpeed(blasterSpeed);
}