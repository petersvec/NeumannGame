#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../../rapidjson/document.h"
#include "../../rapidjson/istreamwrapper.h"
#include "../../rapidjson/writer.h"
#include "../../rapidjson/stringbuffer.h"
#include "../../rapidjson/ostreamwrapper.h"

namespace engine
{
	class JsonToString
	{
	private:
		rapidjson::Document* m_configFile;
		int toString();

	public:
		JsonToString();
		~JsonToString();

	};
}