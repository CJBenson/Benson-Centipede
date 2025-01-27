#ifndef _CentipedeObjectPool
#define _CentipedeObjectPool

#include <stack>
#include "TEAL\CommonElements.h"

class CentipedeHead;
class CentipedeBody;
class CentipedeObjectPool
{
	//Whole object pool is split into heads and bodies
private:
	std::stack<CentipedeHead*> recycledHeads;
	std::stack<CentipedeBody*> recycledBodies;

public:
	CentipedeObjectPool() = default;
	CentipedeObjectPool(const CentipedeObjectPool&) = delete;
	CentipedeObjectPool& operator=(const CentipedeObjectPool&) = delete;
	~CentipedeObjectPool();

	CentipedeHead* GetCentipedeHead(sf::Vector2i start);
	CentipedeBody* GetCentipedeBody(sf::Vector2i start);

	void ReturnCentipedeHead(CentipedeHead* b);
	void ReturnCentipedeBody(CentipedeBody* b);
};

#endif _CentipedeObjectPool
