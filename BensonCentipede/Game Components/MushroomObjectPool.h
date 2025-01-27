#ifndef _MushroomObjectPool
#define _MushroomObjectPool

#include <stack>

class Mushroom;
class MushroomObjectPool
{
private:
	std::stack<Mushroom*> recycledItems;

public:
	MushroomObjectPool() = default;
	MushroomObjectPool(const MushroomObjectPool&) = delete;
	MushroomObjectPool& operator=(const MushroomObjectPool&) = delete;
	~MushroomObjectPool();

	Mushroom* GetMushroom();

	void ReturnMushroom(Mushroom* b);
};


#endif _MushroomObjectPool