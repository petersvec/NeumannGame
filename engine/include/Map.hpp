#pragma once
#include <vector> 
#include "../include/Tile.hpp";
#define MAX_MAP_SIZE 10000

namespace engine
{
	class Map
	{
	private:
		std::vector<std::vector<Tile> > map;
	public:
		Map();
		//Map(const size_t size);
		~Map();

		size_t getMapSize();
	};
}