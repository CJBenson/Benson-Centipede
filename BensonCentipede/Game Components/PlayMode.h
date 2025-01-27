#ifndef _PlayMode
#define _PlayMode

#include "TEAL\CommonElements.h"

class MushroomManager;
class FleaSpawner;
class InputSystem;
class Blaster;
class WaveManager;
class PlayMode : public Scene
{
public:
	PlayMode() = default;
	PlayMode(const PlayMode&) = delete;
	PlayMode& operator=(const PlayMode&) = delete;
	~PlayMode() = default;

	virtual void Initialize();
	virtual void Terminate();
};

#endif _PlayMode