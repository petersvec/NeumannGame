#pragma once
#include "../include/Tile.hpp";

namespace engine
{
	class Planet : public Tile
	{
	private:
		//Private variables
		unsigned char ownership;									//Who owns the planet tile: 0-nobody, 1-first player, 2-second player
	
	public:
		//Constructors & destructor
		Planet();

		//Public functions
	};
}