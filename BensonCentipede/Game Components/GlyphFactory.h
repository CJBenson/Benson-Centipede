#ifndef _GlyphFactory
#define _GlyphFactory

#include "TEAL\CommonElements.h"
#include "GlyphObjectPool.h"
#include "Glyph.h"

class SpriteSheet;

class GlyphFactory
{
private:
	static GlyphFactory* ptrInstance;

	static GlyphFactory& Instance() {
		if (ptrInstance == nullptr)
			ptrInstance = new GlyphFactory();
		return *ptrInstance;
	}

	GlyphFactory() = default;
	GlyphFactory(const GlyphFactory&) = delete;
	GlyphFactory& operator=(const GlyphFactory&) = delete;
	~GlyphFactory() = default;

	GlyphObjectPool GlyphPool;

	Glyph* privCreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	void privRecycleGlyph(Glyph* b);

public:
	static Glyph* CreateGlyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos) { return Instance().privCreateGlyph(sheet, cellInd, pos); }
	static void RecycleGlyph(Glyph* b) { Instance().privRecycleGlyph(b); }

	static void Terminate();
};

#endif _GlyphFactory
