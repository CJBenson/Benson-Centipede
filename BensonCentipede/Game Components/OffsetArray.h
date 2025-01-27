#ifndef _OffsetArray
#define _OffsetArray

#include "TEAL\CommonElements.h"

struct OffsetArray
{
	static const int ARRAY_SIZE = 8;

	sf::Vector2f offsets[ARRAY_SIZE];

	OffsetArray(sf::Vector2f o[ARRAY_SIZE]);
};

#endif _OffsetArray