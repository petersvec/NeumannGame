#pragma once
#include "../include/Tile.hpp";

namespace engine
{
	class Planet : public Tile {
	private:
		int ownership;									// kto vlastni tile: 0-nikto, 1-prvy hrac, 2-druhy hrac
	public:
		Planet();
	};
}