#include "Wave.h"


Wave::Wave()
{
	fleaActive = false;
	scorpActive = false;
	spiderActive = false;

	centiSpeed = 0.0f;
	soloHeads = 0;
	segmentNum = 0;

	scorpFreq = 9999.0f;
	spiderFreq = 9999.0f;

	minShrooms = 9999;
}
Wave::Wave(bool fA, bool scA, bool spA, float cS, int sH, int sN, float scF, float spF, int mS)
{
	fleaActive = fA;
	scorpActive = scA;
	spiderActive = spA;

	centiSpeed = cS;
	soloHeads = sH;
	segmentNum = sN;

	scorpFreq = scF;
	spiderFreq = spF;

	minShrooms = mS;
}