#include "../include/MapGenerator.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace engine
{
	void MapGenerator::generateMap(Map map)
	{
		unsigned short height = map.getHeight();
		unsigned short width = map.getWidth();
		srand(time(NULL));
		for (unsigned short i = 0; i < 2500000; ++i)
		{
			unsigned short x = rand() % height;
			unsigned short y = rand() % width;
			unsigned short type = rand() % 3 + 1;
			map.setTile(x, y, type);
		}

		for (size_t i = 0; i < 5000; ++i)
		{
			for (size_t j = 0; j < 5000; ++j)
			{
				TilePtr a = map.getTile(i, j);
				std::cout << a.get()->getType() << " ";
			}
			std::cout << '\n';
		}
	}
}