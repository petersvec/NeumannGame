#include "../include/Map.hpp"
#include "../../game/include/Tile.hpp"

namespace engine
{
	Map::Map()
	{
		m_mapHeight = 0;
		m_mapWidth = 0;
		m_land = 0;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, nullptr));

		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				m_map[i][j] = std::make_shared<game::Tile>(0);
			}
		}

		setSpritesPosition();
	}

	Map::Map(unsigned short mapSize)
	{
		m_mapHeight = mapSize;
		m_mapWidth = mapSize;
		m_land = 0;
		m_map.resize(m_mapHeight, std::vector<TilePtr>(m_mapWidth, nullptr));

		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				m_map[i][j] = std::make_shared<game::Tile>(0);
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
				m_map[i][j] = std::make_shared<game::Tile>(0);
			}
		}

		setSpritesPosition();
	}

	unsigned short Map::getLand()
	{
		return m_land;
	}

	void Map::setLand(unsigned short land)
	{
		m_land += land;
	}

	void Map::setSpritesPosition()
	{
		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				(m_map[i][j])->setPosition(i * 50.F, j * 50.F);
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

	std::pair<unsigned short, unsigned short> Map::getTileXY(TilePtr tilePtr)
	{
		for (unsigned short i = 0; i < m_mapHeight; ++i)
		{
			for (unsigned short j = 0; j < m_mapWidth; ++j)
			{
				if (m_map[i][j] == tilePtr)
				{
					return std::make_pair(i, j);
				}
			}
		}
		return std::make_pair(G_MAX_MAP_SIZE, G_MAX_MAP_SIZE);
	}

	void Map::setTile(unsigned short mapHeight, unsigned short mapWidth, unsigned char type)
	{
		m_map[mapHeight][mapWidth]->setType(type);
	}
}