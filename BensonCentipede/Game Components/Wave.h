#ifndef _Wave
#define _Wave

struct Wave
{
	Wave();
	Wave(bool fA, bool scA, bool spA, float cS, int sH, int sN, float scF, float spF, int mS);

	bool fleaActive;
	bool scorpActive;
	bool spiderActive;

	float centiSpeed;
	int soloHeads;
	int segmentNum;

	float scorpFreq;
	float spiderFreq;

	int minShrooms;
};

#endif _Wave