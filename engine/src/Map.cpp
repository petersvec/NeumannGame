#include <iostream>
#include "../include/Map.hpp"
const short int G_GENERATIONS = 8;

namespace engine
{
	Map::Map() : m_map() {}

	Map::Map(unsigned short mapSize)
	{
		m_map
	}

	Map::Map(unsigned short mapWidth, unsigned short mapHeight)
	{
		m_map
	}
	
	Map::~Map()
	{
		delete &m_map;
	}

	TilePtr Map::getTile(unsigned short xCoordinate, unsigned short yCoordinate)
	{
		return m_map[xCoordinate][yCoordinate];
	}
}