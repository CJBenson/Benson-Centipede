// SimpleTextDemo
// Andre Berthiaume, May 2013

#ifndef _HUD
#define _HUD

#include "TEAL/CommonElements.h"
#include <list>
#include "AwesomeFont.h"

class HUD : public GameObject
{
public:
	HUD();
	HUD(const HUD& r) = delete;
	HUD& operator =(const HUD& r) = delete;
	~HUD() = default;

	void UpdateP1Score(std::string newScore);
	void UpdateP2Score(std::string newScore);
	void UpdateP1Lives(std::string newLives);
	void UpdateP2Lives(std::string newLives);


	virtual void Draw();
	virtual void Destroy();

private:
	AwesomeFont myfont;

	std::list<Glyph*> symbols;
	sf::Vector2f nextpos;

	std::string p1Score;
	std::string p2Score;

	std::string p1Lives;
	std::string p2Lives;

	const sf::Vector2f p1ScoreLPos = sf::Vector2f(0, 0);
	const sf::Vector2f p2ScoreRPos = sf::Vector2f(464.0, 0);
};


#endif _HUD