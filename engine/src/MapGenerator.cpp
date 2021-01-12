#include "../include/MapGenerator.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace engine
{
	void MapGenerator::generateMap(Map map, unsigned short numberOfPlanets, unsigned char maxRadiusOfPlanet)
	{
		unsigned short height = map.getHeight();
		unsigned short width = map.getWidth();
		srand(time(NULL));
		for (unsigned short i = 0; i < numberOfPlanets; ++i)
		{
			unsigned short x = rand() % height;
			unsigned short y = rand() % width;
			unsigned char type = rand() % 3 + 1;
			unsigned char radius = rand() % maxRadiusOfPlanet;
			map.setTile(x, y, type);
			setPlanet(map, x, y, type, radius);
		}

		for (size_t i = 0; i < height; ++i)
		{
			for (size_t j = 0; j < width; ++j)
			{
				TilePtr a = map.getTile(i, j);
				std::cout << a.get()->getType() << " ";
			}
			std::cout << '\n';
		}
	}

	void MapGenerator::setPlanet(Map map, unsigned short x, unsigned short y, unsigned char type, unsigned char radius)
	{
		for (unsigned char i = 0; i <= radius - 1; ++i)
		{
			if (x - i >= 0)
			{
				map.setTile(x - i, y, type);
			}

			if (x + i < map.getHeight())
			{
				map.setTile(x + i, y, type);
			}

			if (y - i >= 0)
			{
				map.setTile(x, y - i, type);
			}

			if (y + i < map.getWidth())
			{
				map.setTile(x, y + i, type);
			}
		}

		for (unsigned char j = 0; j <= radius - 1; ++j)
		{
			if (x - j >= 0 && y - j >= 0)
			{
				map.setTile(x - j, y - j, type);
			}

			if (x + j < map.getHeight() && y - j >= 0)
			{
				map.setTile(x + j, y - j, type);
			}

			if (x + j < map.getHeight() && y - j >= 0)
			{
				map.setTile(x + j, y - j, type);
			}

			if (x + j < map.getHeight() && y + j < map.getWidth())
			{
				map.setTile(x + j, y + j, type);
			}
		}
	}
}