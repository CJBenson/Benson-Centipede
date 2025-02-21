// SpriteSheet
// Andre Berthiaume, May 2013

#ifndef _SpriteSheet
#define _SpriteSheet

#include "SFML\Graphics.hpp"
#include "Glyph.h"
#include <vector>

class SpriteSheet
{
public:
	SpriteSheet() = delete;
	SpriteSheet(const SpriteSheet&) = delete;
	SpriteSheet& operator=(const SpriteSheet&) = delete;
	virtual ~SpriteSheet();

	SpriteSheet(sf::Texture& tex, int CellCountHor, int CellCountVert);
	int CellWidth();
	int CellHeight();
	void Draw(int i, sf::Vector2f pos);

	Glyph* GetGlyph(char c, sf::Vector2f pos);

private:
	std::vector<sf::Sprite*> GlyphCollection;
	sf::Texture Fontexture;
	int cellWidth;
	int cellHeight;

	virtual int CharToIndex(char& c) = 0;  // abstract method. 
};


#endif _SpriteSheet