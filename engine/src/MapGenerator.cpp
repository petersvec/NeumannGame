#include "../include/MapGenerator.hpp"

namespace engine
{
	void MapGenerator::generateMap(Map* map, unsigned short numberOfPlanets, unsigned char maxRadiusOfPlanet)
	{
		unsigned short height = map->getHeight();
		unsigned short width = map->getWidth();
		srand(static_cast<unsigned int>(time(nullptr)));
		
		for (unsigned short i = 0; i < numberOfPlanets; ++i)
		{
			unsigned short x = rand() % height;
			unsigned short y = rand() % width;
			unsigned char type = rand() % 3 + 1;
			unsigned char radius = rand() % maxRadiusOfPlanet + 1;
			map->setTile(x, y, type);
			map->setLand(1);

			if (radius == 0)
			{
				continue;
			}

			unsigned short polovica = 0;
			bool flag = true;

			for (unsigned char i = x - radius; i <= x + radius; ++i)
			{
				if (i < 0 || i >= height)
				{
					continue;
				}

				for (unsigned char j = y - polovica; j <= y + polovica; ++j)
				{
					if (j < 0 || j >= width)
					{
						continue;
					}

					map->setTile(i, j, type);
					map->setLand(1);
				}

				if (polovica < radius && flag)
				{
					++polovica;
				}
				else
				{
					flag = false;
					--polovica;
				}
			}

			if (map->getTile(x, y) == 0)
			{
				map->setTile(x, y, type);
				map->setLand(1);
				setPlanet(map, x, y, type, radius);
			}
		}
	}

	void MapGenerator::setPlanet(Map* map, unsigned short x, unsigned short y, unsigned char type, unsigned char radius)
	{
		if (radius == 0)
		{
			return;
		}

		for (unsigned char i = x - radius; i < x + radius; ++i)
		{
			if (i < 0 || i >= map->getHeight())
			{
				continue;
			}

			for (unsigned char j = y - radius; j <= y + radius; ++j)
			{
				if (j < 0 || j >= map->getWidth())
				{
					continue;
				}

				if (map->getTile(i, j) == 0)
				{
					map->setTile(i, j, type);
					map->setLand(1);
				}
			}
		}
	}
}