#include "../include/Map.hpp"

namespace engine
{
	Map::Map()
	{
		m_mapHeight = 0;
		m_mapWidth = 0;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, nullptr));

		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				m_map[i][j] = std::make_shared<Tile>(0);
			}
		}

		setSpritesPosition();
	}

	Map::Map(unsigned short mapSize)
	{
		m_mapHeight = mapSize;
		m_mapWidth = mapSize;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, nullptr));

		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				m_map[i][j] = std::make_shared<Tile>(0);
			}
		}

		setSpritesPosition();
	}

	Map::Map(unsigned short mapHeight, unsigned short mapWidth)
	{
		m_mapHeight = mapHeight;
		m_mapWidth = mapWidth;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, nullptr));

		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				m_map[i][j] = std::make_shared<Tile>(0);
			}
		}

		setSpritesPosition();
	}

	void Map::setSpritesPosition()
	{
		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				(m_map[i][j])->setPosition(i * 50.F, j * 50.0F);
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
		m_map[mapHeight][mapWidth]->setType(type);
	}
}