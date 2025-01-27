#include "GlyphObjectPool.h"
#include "Glyph.h"

GlyphObjectPool::~GlyphObjectPool()
{
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Glyph* GlyphObjectPool::GetGlyph()
{
	Glyph* f;

	if (recycledItems.empty())
	{
		f = new Glyph();
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();
	}

	return f;
}

void GlyphObjectPool::ReturnGlyph(Glyph* b)
{
	recycledItems.push(static_cast<Glyph*>(b));
}