#pragma once
#include "Tile.hpp"

namespace engine
{
	class Map {
	public:
		Map();
		Tile **tile;
		int mapsize;
		void updateMap();
	private:
	};
}