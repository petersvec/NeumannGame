#pragma once
#include "Map.hpp"

namespace engine
{
	class MapGenerator
	{
	private:
		Map* map;
	public:
		MapGenerator();
		~MapGenerator();
	};
}