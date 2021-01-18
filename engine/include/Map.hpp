#pragma once
#include <memory>
#include <vector> 
#include "../include/Tile.hpp"
using TilePtr = std::shared_ptr<engine::Tile>;
using MapPtr = std::vector<std::vector<TilePtr>>;
//using MapPtr = std::shared_ptr<std::vector<std::vector<TilePtr>>>;

namespace engine
{
	class Map
	{
	private:
		MapPtr m_map;
		unsigned short m_mapHeight, m_mapWidth;


	public:
		Map();
		Map(unsigned short mapSize);
		Map(unsigned short mapHeight, unsigned short mapWidth);

		MapPtr getMap();
		unsigned short getHeight();
		unsigned short getWidth();
		TilePtr getTile(unsigned short mapHeight, unsigned short mapWidth);
		void setTile(unsigned short mapHeight, unsigned short mapWidth, unsigned char type);
	};
}
