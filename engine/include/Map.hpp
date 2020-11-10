#pragma once
#include "Tile.hpp"

namespace engine
{
	class Map {
	public:
		Map();
		Tile tile[10][10];
		int mapsize;
		void updateMap();
	private:
	};
}