#pragma once
#include "../../rapidjson/document.h"

namespace engine
{
	class JsonParser
	{
	private:
		rapidjson::Document m_gameConfigFile;

	public:

		void setGameConfig(const char* jsonFile);
		unsigned short getMaxMapSize();
		unsigned short getMapHeight();
		unsigned short getMapWidth();
	};
}