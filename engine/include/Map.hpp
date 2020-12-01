#pragma once
#include <vector> 
#include "../include/Tile.hpp";
const short int G_MAX_MAP_SIZE = 10000;
using TilePtr = std::shared_ptr<engine::Tile>;
using MapPtr = std::vector<std::vector<TilePtr>>;

namespace engine
{
	class Map
	{
	private:
		MapPtr m_map;


	public:
		Map();
		Map(unsigned short mapSize);
		Map(unsigned short mapWidth, unsigned short mapHeight);
		~Map();

		TilePtr getTile(unsigned short mapWidth, unsigned short mapHeight);
	};
}