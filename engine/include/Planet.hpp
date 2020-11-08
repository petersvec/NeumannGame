#pragma once
#include "../include/Tile.hpp";

namespace engine
{
	class Planet : public Tile
	{
	private:
		unsigned char ownership;									//Who owns the tile: 0-nobody, 1-first player, 2-second player
	public:
		Planet();
	};
}