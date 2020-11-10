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

	Map::Map(const Map& m)
	{
		this->map.resize(m.map.size());
		for (size_t i = 0; i < m.map.size(); ++i)
		{
			this->map[i].resize(m.map.size());
			for (size_t j = 0; j < m.map.size(); ++j)
			{
				this->map[i][j] = m.map[i][j];
			}
		}
	}
	
	Map::~Map()
	{
		destroyMap();
	}

	//Operators



	//Private functions

	void Map::updateMap()
	{
		Map m = *this;
		for (size_t k = 0; k < GENERATIONS; ++k)
		{
			for (size_t i = 0; i < getMapSize(); ++i)
			{
				for (size_t j = 0; j < getMapSize(); ++j)
				{
					if (m.map[i][j] == 1)
					{
						if (!isLinked(i, j, 1, m)) {
							this->map[i][j] = 0;
						}
					}
					else
					{
						if (!isLinked(i, j, 0, m)) {
							this->map[i][j] = 1;
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

	bool Map::isLinked(size_t i, size_t j, unsigned char type)
	{
		if (j != 0 && this->map[i][j - 1] == type)
		{
			return true;
		}
		if (j != (this->getMapSize() - 1) && this->map[i][j + 1] == type)
		{
			return true;
		}
		if (i != (this->getMapSize() - 1) && this->map[i + 1][j] == type)
		{
			return true;
		}
		if (i != 0 && this->map[i - 1][j] == type)
		{
			return true;
		}
		return false;
	}

	//Public functions
	size_t Map::getMapSize()
	{
		return this->map.size();	//redundant (there is no custom sized maps (yet) //return MAX_MAP_SIZE;
	}
	
	std::vector<std::vector<Tile>> Map::getMap()
	{
		return this->map;
	}
}