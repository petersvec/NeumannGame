#include <iostream>
#include "../include/Map.hpp"
#define GENERATIONS 8

namespace engine
{
	//Constructors & destructor
	Map::Map()
	{
		this->map.resize(MAX_MAP_SIZE);
		for (size_t i = 0; i < MAX_MAP_SIZE; ++i)
		{
			this->map[i].resize(MAX_MAP_SIZE);
			for (size_t j = 0; j < MAX_MAP_SIZE; ++j)
			{
				this->map[i][j] = Tile();
			}
		}
		updateMap();
	}
	
	Map::~Map()
	{
		destroyMap();
	}

	//Private functions

	void Map::updateMap()
	{
		for (size_t k = 0; k < GENERATIONS; ++k)
		{
			for (size_t i = 0; i < getMapSize(); ++i)
			{
				for (size_t j = 0; j < getMapSize(); ++j)
				{
					if (this->map[i][j] == 1) {
						if (!isLinked(i, j, 1)) {
							drawWater(i, j);
						}
					}
					else {
						if (!isLinked(i, j, 0)) {
							drawLand(i, j);
						}
					}
				}
			}
		}
	}

	void Map::destroyMap()
	{
		for (size_t i = 0; i < getMapSize(); ++i)
		{
			this->map[i].resize(0);
			this->map[i].shrink_to_fit();
		}
		this->map.resize(0);
		this->map.shrink_to_fit();
	}

	//Public functions
	size_t Map::getMapSize()
	{
		return this->map.size();	//redundant (there is no custom sized maps (yet) //return MAX_MAP_SIZE;
	}
}