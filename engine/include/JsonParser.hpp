#pragma once
#include <cstdio>
#include <string>
#include <map>
#include "../../rapidjson/document.h"
#include "../../rapidjson/filereadstream.h"
#include "../include/Map.hpp"

namespace engine
{
	class JsonParser;
	extern std::unique_ptr<JsonParser> config;

	class JsonParser
	{
	private:
		rapidjson::Document m_gameConfigFile;
		std::string m_configType;

		void setConfigType(const std::string &jsonType);

	public:

		bool setGameConfig(const std::string &jsonFile, const std::string &jsonType);
		unsigned short getMapHeight();
		unsigned short getMapWidth();
		unsigned short getNumberOfPlanets();
		unsigned getTileSize() const;
		unsigned char getMaxRadiusOfPlanet();
		unsigned char getTileSize();
		std::map<std::string, std::string> getTextures();
	};
}