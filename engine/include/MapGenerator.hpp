#pragma once
#include "Map.hpp"

namespace engine
{
	class MapGenerator
	{
	private:

	public:
		MapGenerator();
		~MapGenerator();

		void generateMap(Map map);
	};
}