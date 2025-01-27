#ifndef _WaveManager
#define _WaveManager

#include "TEAL/CommonElements.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Wave;
class WaveManager
{
public:
	WaveManager();
	WaveManager(const WaveManager& r) = delete;
	WaveManager& operator =(const WaveManager& r) = delete;
	~WaveManager() = default;

	Wave GetWaveData(int waveNum);

private:
	string fullData;
	const int finalWave = 5;
};


#endif _WaveManager