#include "GlyphFactory.h"
#include "Glyph.h"

GlyphFactory* GlyphFactory::ptrInstance = nullptr;


Glyph* GlyphFactory::privCreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos)
{
	Glyph* s = GlyphPool.GetGlyph();
	s->Initialize(sheet, cellInd, pos);
	return s;
}

void GlyphFactory::privRecycleGlyph(Glyph* b)
{
	GlyphPool.ReturnGlyph(b);
}

void GlyphFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}