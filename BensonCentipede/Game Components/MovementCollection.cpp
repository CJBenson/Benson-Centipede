#include "MovementCollection.h"
#include "OffsetArray.h"
#include "TEAL\CommonElements.h"

//Baseline directions
sf::Vector2f hPos = sf::Vector2f(2.0f, 0);
sf::Vector2f hNeg = sf::Vector2f(-2.0f, 0);
sf::Vector2f vPos = sf::Vector2f(0, -2.0f);
sf::Vector2f vNeg = sf::Vector2f(0, 2.0f);
sf::Vector2f zero = sf::Vector2f(0, 0);

//8-piece arrays of those
sf::Vector2f right[OffsetArray::ARRAY_SIZE] = { hPos, hPos, hPos, hPos, hPos, hPos, hPos, hPos };
sf::Vector2f left[OffsetArray::ARRAY_SIZE] = { hNeg, hNeg, hNeg, hNeg, hNeg, hNeg, hNeg, hNeg };
sf::Vector2f up[OffsetArray::ARRAY_SIZE] = { vPos, vPos, vPos, vPos, vPos, vPos, vPos, vPos };
sf::Vector2f down[OffsetArray::ARRAY_SIZE] = { vNeg, vNeg, vNeg, vNeg, vNeg, vNeg, vNeg, vNeg };
sf::Vector2f stationary[OffsetArray::ARRAY_SIZE] = { zero, zero, zero, zero, zero, zero, zero, zero, };

//Construction of OffsetArray objects with those directional arrays
const OffsetArray MovementCollection::OffsetsStraightRight = OffsetArray(right);
const OffsetArray MovementCollection::OffsetsTurnUpEndRight = OffsetArray(up);
const OffsetArray MovementCollection::OffsetsTurnDownEndRight = OffsetArray(down);
const OffsetArray MovementCollection::OffsetsStraightLeft = OffsetArray(left);
const OffsetArray MovementCollection::OffsetsTurnUpEndLeft = OffsetArray(up);
const OffsetArray MovementCollection::OffsetsTurnDownEndLeft = OffsetArray(down);
const OffsetArray MovementCollection::OffsetsStationary = OffsetArray(stationary);