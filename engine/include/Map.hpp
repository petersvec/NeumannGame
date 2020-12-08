#pragma once
#include <memory>
#include <vector> 
#include "../include/Tile.hpp";
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

		TilePtr getTile(unsigned short mapWidth, unsigned short mapHeight);
	};
}
