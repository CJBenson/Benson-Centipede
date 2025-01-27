#include "OffsetArray.h"

OffsetArray::OffsetArray(sf::Vector2f o[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		offsets[i] = o[i];
	}
}