#ifndef _InputSystem
#define _InputSystem

#include "TEAL\CommonElements.h"

class Blaster;
enum class Systems;

class InputSystem : public GameObject
{
public:
	InputSystem();
	InputSystem(const InputSystem& r) = delete;
	InputSystem& operator =(const InputSystem& r) = delete;
	virtual ~InputSystem() = default;

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void FireBlaster();

	void SetBlaster(Blaster* newB);

protected:
	Blaster* blaster;

	float blasterSpeed;
};

#endif _InputSystem
