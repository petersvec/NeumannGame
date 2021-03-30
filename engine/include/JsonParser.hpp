#pragma once
#include <cstdio>
#include <string>
#include <map>
#include "../../rapidjson/document.h"
#include "../../rapidjson/filereadstream.h"
#include "../include/Map.hpp"

namespace engine
{
	class JsonParser
	{
	private:
		rapidjson::Document m_gameConfigFile;
		std::string m_configType;

		void setConfigType(const char*);

	public:

		bool setGameConfig(const char*, const char*);
		unsigned short getMapHeight();
		unsigned short getMapWidth();
		unsigned short getNumberOfPlanets();
		unsigned char getMaxRadiusOfPlanet();
		std::map<std::string, std::string> getTextures();
	};
}