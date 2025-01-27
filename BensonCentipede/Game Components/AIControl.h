#ifndef _AIControl
#define _AIControl

#include "TEAL/CommonElements.h"
#include "InputSystem.h"

class AIControl : public InputSystem
{
public:
	AIControl(Blaster* b);

	AIControl() = delete;
	AIControl(const AIControl& r) = delete;
	AIControl& operator =(const AIControl& r) = delete;
	~AIControl() = default;

	virtual void Update();
	virtual void Destroy();

	virtual void Alarm0();

private:
	void TestEdges();

	bool moving;
	int H;
	int V;

	const float moveDur = 2.0f;
	const float edgePadding = 16.0f;
};
#endif _AIControl