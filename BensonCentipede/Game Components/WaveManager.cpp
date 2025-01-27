#include "WaveManager.h"
#include "Wave.h"

WaveManager::WaveManager()
{
	fullData = "";

	std::ifstream WaveData("WaveData.txt");

	if (WaveData.is_open()) {
		std::string str;

		while (getline(WaveData, str)) {
			fullData += (str + "\n");
		}

		WaveData.close();

		//ConsoleMsg::WriteLine(fullData);
	}
}

Wave WaveManager::GetWaveData(int waveNum)
{
	if (waveNum > finalWave)
		waveNum = finalWave;

	Wave retVal;
	
	std::string targetWave = "Wave " + Tools::ToString(waveNum);
	std::string nextWave = "Wave " + Tools::ToString(waveNum + 1);

	std::string str;

	std::size_t foundStart = fullData.find(targetWave);
	std::size_t foundEnd = fullData.find(nextWave);

	if (foundStart != std::string::npos) {
		//All Values
		bool fleaActive;
		bool scorpActive;
		bool spiderActive;
		
		float centiSpeed;
		
		int soloHeads;
		int bodySegments;
		
		float scorpTimer;
		float spiderTimer;
		int minShrooms;

		//Get the wave text we need
		std::string waveText = fullData.substr(foundStart, foundEnd - foundStart);


		//Flea Spawning-------------------------------------------------------------------------------------
		std::string lineText = "Flea Spawner Active: ";
		std::size_t fleaActiveStart = waveText.find(lineText) + lineText.length();
		std::size_t fleaActiveLength = waveText.find(";", fleaActiveStart) - fleaActiveStart;
		std::string fleaActiveString = waveText.substr(fleaActiveStart, fleaActiveLength);

		if (fleaActiveString == "true")
			fleaActive = true;
		else if (fleaActiveString == "false")
			fleaActive = false;
		else {
			fleaActive = false;
			ConsoleMsg::ShowError("Must be either true or false!");
		}

		//Scorpion Spawning---------------------------------------------------------------------------------
		lineText = "Scorpion Spawner Active: ";
		std::size_t scorpActiveStart = waveText.find(lineText) + lineText.length();
		std::size_t scorpActiveLength = waveText.find(";", scorpActiveStart) - scorpActiveStart;
		std::string scorpActiveString = waveText.substr(scorpActiveStart, scorpActiveLength);

		if (scorpActiveString == "true")
			scorpActive = true;
		else if (scorpActiveString == "false")
			scorpActive = false;
		else {
			scorpActive = false;
			ConsoleMsg::ShowError("Must be either true or false!");
		}

		//Spider Spawning-----------------------------------------------------------------------------------
		lineText = "Spider Spawner Active: ";
		std::size_t spiderActiveStart = waveText.find(lineText) + lineText.length();
		std::size_t spiderActiveLength = waveText.find(";", spiderActiveStart) - spiderActiveStart;
		std::string spiderActiveString = waveText.substr(spiderActiveStart, spiderActiveLength);

		if (spiderActiveString == "true")
			spiderActive = true;
		else if (spiderActiveString == "false")
			spiderActive = false;
		else {
			spiderActive = false;
			ConsoleMsg::ShowError("Must be either true or false!");
		}

		//Centipede Speed------------------------------------------------------------------------------------
		lineText = "Centipede Speed: ";
		std::size_t centiSpeedStart = waveText.find(lineText) + lineText.length();
		std::size_t centiSpeedLength = waveText.find(";", centiSpeedStart) - centiSpeedStart;
		std::string centiSpeedString = waveText.substr(centiSpeedStart, centiSpeedLength);

		centiSpeed = std::stof(centiSpeedString);
		
		//Solo Heads-----------------------------------------------------------------------------------------
		lineText = "Solo Heads: ";
		std::size_t soloHeadsStart = waveText.find(lineText) + lineText.length();
		std::size_t soloHeadsLength = waveText.find(";", soloHeadsStart) - soloHeadsStart;
		std::string soloHeadsString = waveText.substr(soloHeadsStart, soloHeadsLength);

		soloHeads = std::stoi(soloHeadsString);

		//Body Segments--------------------------------------------------------------------------------------
		lineText = "Number of Segments: ";
		std::size_t bodySegmentsStart = waveText.find(lineText) + lineText.length();
		std::size_t bodySegmentsLength = waveText.find(";", bodySegmentsStart) - bodySegmentsStart;
		std::string bodySegmentsString = waveText.substr(bodySegmentsStart, bodySegmentsLength);

		bodySegments = std::stoi(bodySegmentsString);

		//Scorpion Timer-------------------------------------------------------------------------------------
		lineText = "Scorpion Frequency: ";
		std::size_t scorpTimerStart = waveText.find(lineText) + lineText.length();
		std::size_t scorpTimerLength = waveText.find(";", scorpTimerStart) - scorpTimerStart;
		std::string scorpTimerString = waveText.substr(scorpTimerStart, scorpTimerLength);

		scorpTimer = std::stof(scorpTimerString);

		//Spider Timer---------------------------------------------------------------------------------------
		lineText = "Spider Frequency: ";
		std::size_t spiderTimerStart = waveText.find(lineText) + lineText.length();
		std::size_t spiderTimerLength = waveText.find(";", spiderTimerStart) - spiderTimerStart;
		std::string spiderTimerString = waveText.substr(spiderTimerStart, spiderTimerLength);

		spiderTimer = std::stof(spiderTimerString);

		//Mushroom Minimum for Flea Spawning-----------------------------------------------------------------
		lineText = "Minimum Shrooms for Flea Spawning: ";
		std::size_t minShroomsStart = waveText.find(lineText) + lineText.length();
		std::size_t minShroomsLength = waveText.find(";", minShroomsStart) - minShroomsStart;
		std::string minShroomsString = waveText.substr(minShroomsStart, minShroomsLength);

		minShrooms = std::stoi(minShroomsString);

		


		//FINALLY Initialize the Wave
		retVal = Wave(fleaActive, scorpActive, spiderActive, centiSpeed, soloHeads, bodySegments, scorpTimer, spiderTimer, minShrooms);
		 
	}
	return retVal;
}