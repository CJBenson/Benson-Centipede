// SimpleTextDemo
// Andre Berthiaume, May 2013

#include "HUD.h"
#include "GlyphFactory.h"

HUD::HUD()
{
	//Starts as all spaces to black out the spaces
	p1Score = "       ";
	p2Score = "       ";

	p1Lives = "";
	p2Lives = "";
}

void HUD::Destroy()
{
	std::list<Glyph*>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		GlyphFactory::RecycleGlyph(*it);
}

void HUD::UpdateP1Score(std::string newScore)
{
	p1Score = newScore;

	std::string p1Total = p1Score + p1Lives;
	nextpos = p1ScoreLPos;

	//Score and lives put together in one string and written out
	for (size_t i = 0; i < p1Total.length(); i++)
	{
		symbols.push_back(myfont.GetGlyph(p1Total.at(i), nextpos));

		// we must update the next position ourselves
		nextpos.x += myfont.CellWidth();
	}
}
void HUD::UpdateP2Score(std::string newStr)
{
	p2Score = newStr;

	std::string p2Total = p2Lives + p2Score;
	nextpos = p2ScoreRPos;

	//writes backwards so it's always aligned with right side of screen
	for (size_t i = p2Total.length(); i > 0; i--)
	{
		symbols.push_back(myfont.GetGlyph(p2Total.at(i - 1), nextpos));

		nextpos.x -= myfont.CellWidth();
	}
}


void HUD::UpdateP1Lives(std::string newLives)
{
	p1Lives = newLives;

	std::string p1Total = p1Score + p1Lives;
	nextpos = p1ScoreLPos;


	for (size_t i = 0; i < p1Total.length(); i++)
	{
		symbols.push_back(myfont.GetGlyph(p1Total.at(i), nextpos));

		// we must update the next position ourselves
		nextpos.x += myfont.CellWidth();
	}
}
void HUD::UpdateP2Lives(std::string newLives)
{
	p2Lives = newLives;

	std::string p2Total = p2Lives + p2Score;
	nextpos = p2ScoreRPos;


	for (size_t i = p2Total.length(); i > 0; i--)
	{
		symbols.push_back(myfont.GetGlyph(p2Total.at(i - 1), nextpos));

		// we must update the next position ourselves
		nextpos.x -= myfont.CellWidth();
	}
}


void HUD::Draw()
{
	std::list<Glyph*>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		(*it)->Draw();
}