#include <iostream>
#include "../include/Map.hpp"

namespace engine
{
	Map::Map()
	{
		m_map.resize(10000, std::vector<TilePtr>(10000, std::shared_ptr<engine::Tile>(new Tile(0))));
		
	}

	Map::Map(unsigned short mapSize)
	{
		m_map.resize(mapSize, std::vector<TilePtr>(mapSize, std::shared_ptr<engine::Tile>(new Tile(0))));

	}

	Map::Map(unsigned short mapWidth, unsigned short mapHeight)
	{
		m_map.resize(mapHeight, std::vector<TilePtr>(mapWidth, std::shared_ptr<engine::Tile>(new Tile(0))));

	}

	TilePtr Map::getTile(unsigned short xCoordinate, unsigned short yCoordinate)
	{
		return m_map[xCoordinate][yCoordinate];
	}
}