#ifndef _AttractorController
#define _AttractorController

#include "TEAL\CommonElements.h"

class AttractorController : public GameObject
{
public:
	AttractorController();
	AttractorController(const AttractorController& r) = delete;
	AttractorController& operator=(const AttractorController& r) = delete;
	~AttractorController() = default;

	virtual void Destroy();

	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};

#endif _AttractorController
