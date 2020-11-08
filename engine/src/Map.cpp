#include <iostream>
#include "../include/Map.hpp"


namespace engine
{
	Map::Map()
	{
		this->map.resize(MAX_MAP_SIZE);
		for (size_t i = 0; i < MAX_MAP_SIZE; ++i)
		{
			this->map[i].resize(MAX_MAP_SIZE);
		}
	}

	// custom map size (for example: different difficulties)
	/*
	Map::Map(const size_t size)
	{
		try
		{
			if (size > MAX_MAP_SIZE)
			{
				throw - 1;
			}
		}
		catch (int e)
		{
			if (e == -1)
			{
				std::cout << "Size of the map exceeds maximum allowed size.";
			}
		}

		this->map.resize(size);
		for (size_t i = 0; i < size; ++i)
		{
			this->map[i].resize(size);
		}
	}*/
	
	Map::~Map()
	{
		for (size_t i = 0; i < getMapSize(); ++i)
		{
			this->map[i].resize(0);
			this->map[i].shrink_to_fit();
		}

		this->map.resize(0);
		this->map.shrink_to_fit();
	}

	size_t Map::getMapSize()
	{
		return this->map.size();
	}
}