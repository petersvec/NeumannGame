#pragma once
#include <memory>
#include <vector> 
#include "Tile.hpp"
using TilePtr = std::shared_ptr<engine::Tile>;
using MapPtr = std::vector<std::vector<TilePtr>>;
//using MapPtr = std::shared_ptr<std::vector<std::vector<TilePtr>>>;
const unsigned short G_MIN_MAP_SIZE = ((short)50);
const unsigned short G_MAX_MAP_SIZE = ((short)10000);
const unsigned short G_MIN_NUMBER_OF_PLANETS = ((short)50);
const unsigned short G_MIN_RADIUS_OF_PLANET = ((short)2);

namespace engine
{
	class Map
	{
	private:
		MapPtr m_map;
		unsigned short m_mapHeight, m_mapWidth;

		void setSpritesPosition();

	public:
		Map();
		Map(unsigned short);
		Map(unsigned short, unsigned short);

		MapPtr getMap();
		unsigned short getHeight();
		unsigned short getWidth();
		TilePtr getTile(unsigned short, unsigned short);
		void setTile(unsigned short, unsigned short, unsigned char);
	};
}
