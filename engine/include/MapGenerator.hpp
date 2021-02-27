#pragma once
#include "Map.hpp"

namespace engine
{
	class MapGenerator
	{
	private:
		void setPlanet(Map map, unsigned short x, unsigned short y, unsigned char type, unsigned char radius);

	public:
		void generateMap(Map* map, unsigned short numberOfPlanets, unsigned char maxRadiusOfPlanet);
	};
}