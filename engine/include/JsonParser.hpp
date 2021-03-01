#pragma once
#include <fstream>
#include "../../rapidjson/document.h"
#include "../../rapidjson/istreamwrapper.h"

namespace engine
{
	class JsonParser
	{
	private:
		rapidjson::Document* m_gameConfigFile;

	public:

		bool setGameConfig(const char*, const char*);
		unsigned short getMapHeight();
		unsigned short getMapWidth();
		unsigned short getNumberOfPlanets();
		unsigned char getMaxRadiusOfPlanet();
	};
}