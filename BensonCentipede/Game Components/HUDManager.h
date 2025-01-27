#ifndef _HUDManager
#define _HUDManager

#include "TEAL/CommonElements.h"
#include "AwesomeFont.h"

class HUD;

class HUDManager
{
public:
	HUDManager();
	HUDManager(const HUDManager& r) = delete;
	HUDManager& operator =(const HUDManager& r) = delete;
	~HUDManager() = default;

	void CreateHUD();

	void SetPlayer1Score(int newScore);
	void SetPlayer2Score(int newScore);

	void SetPlayer1Lives(int newLives);
	void SetPlayer2Lives(int newLives);

private:
	HUD* currHUD;
};


#endif _HUDManager