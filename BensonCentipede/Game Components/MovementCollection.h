#ifndef _MovementCollection
#define _MovementCollection

struct OffsetArray;
class MovementCollection
{
public:
	static const int OFFSET_SIZE = 8;

	static const OffsetArray OffsetsStraightRight;
	static const OffsetArray OffsetsTurnUpEndRight;
	static const OffsetArray OffsetsTurnDownEndRight;
	static const OffsetArray OffsetsStraightLeft;
	static const OffsetArray OffsetsTurnUpEndLeft;
	static const OffsetArray OffsetsTurnDownEndLeft;
	static const OffsetArray OffsetsStationary;
};

#endif _MovementCollection