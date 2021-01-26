#include "../include/Map.hpp"

namespace engine
{
	Map::Map()
	{
		m_mapHeight = 1000;
		m_mapWidth = 1000;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, TilePtr(new Tile(0))));
		setSprites();
	}

	Map::Map(unsigned short mapSize)
	{
		m_mapHeight = mapSize;
		m_mapWidth = mapSize;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, std::shared_ptr<Tile>(new Tile(0))));
		setSprites();
	}

	Map::Map(unsigned short mapHeight, unsigned short mapWidth)
	{
		m_mapHeight = mapHeight;
		m_mapWidth = mapWidth;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, std::make_shared<Tile>(0)));
		setSprites();
	}

	void Map::setSprites()
	{
		for (int i = 0; i < m_mapHeight; i++)
		{
			for (int j = 0; j < m_mapWidth; j++)
			{
				m_map[i][j].get()->getSprite().setPosition(i * 50, j * 50);
			}
		}
	}

	MapPtr Map::getMap()
	{
		return m_map;
	}

	unsigned short Map::getHeight()
	{
		return m_mapHeight;
	}

	unsigned short Map::getWidth()
	{
		return m_mapWidth;
	}

	TilePtr Map::getTile(unsigned short mapHeight, unsigned short mapWidth)
	{
		return m_map[mapHeight][mapWidth];
	}

	void Map::setTile(unsigned short mapHeight, unsigned short mapWidth, unsigned char type)
	{
		m_map[mapHeight][mapWidth] = TilePtr(new Tile(type));
	}
}