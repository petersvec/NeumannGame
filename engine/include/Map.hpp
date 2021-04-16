#pragma once
#include <memory>
#include <vector>
#include "../../game/include/Tile.hpp"

namespace engine
{
	const unsigned short G_MIN_MAP_SIZE = 50;
	const unsigned short G_MAX_MAP_SIZE = 10000;
	const unsigned short G_MIN_NUMBER_OF_PLANETS = 50;
	const unsigned short G_MIN_RADIUS_OF_PLANET = 2;
	const unsigned short G_MIN_TILE_SIZE = 50;
	using TilePtr = std::shared_ptr<game::Tile>;
	using MapPtr = std::vector<std::vector<TilePtr>>;

	class Map
	{
	private:
		MapPtr m_map;
		unsigned short m_mapHeight, m_mapWidth, m_land;

		void setSpritesPosition();

	public:
		Map();
		Map(unsigned short);
		Map(unsigned short, unsigned short);

		MapPtr getMap();
		unsigned short getHeight();
		unsigned short getWidth();
		unsigned short getLand();
		void setLand(unsigned short);
		TilePtr getTile(unsigned short, unsigned short);
		std::pair<unsigned short, unsigned short> getTileXY(TilePtr);
		void setTile(unsigned short, unsigned short, unsigned char);
	};
}
