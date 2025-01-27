#include "HUDManager.h"
#include "HUD.h"

HUDManager::HUDManager()
{
	currHUD = nullptr;
}

void HUDManager::CreateHUD()
{
	currHUD = new HUD();
}

void HUDManager::SetPlayer1Score(int newScore)
{
	currHUD->UpdateP1Score(Tools::ToString(newScore));
}
void HUDManager::SetPlayer2Score(int newScore)
{
	currHUD->UpdateP2Score(Tools::ToString(newScore));
}

void HUDManager::SetPlayer1Lives(int newLives)
{
	std::string life = "^";
	std::string lives = "";

	for (int i = 0; i < newLives; i++) {
		lives += life;
	}

	lives += "  ";

	currHUD->UpdateP1Lives(lives);
}
void HUDManager::SetPlayer2Lives(int newLives)
{
	std::string life = "^";
	std::string lives = "  ";

	for (int i = 0; i < newLives; i++) {
		lives += life;
	}

	currHUD->UpdateP2Lives(lives);
}