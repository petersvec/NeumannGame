#pragma once
#include "Tile.hpp"

namespace engine
{
	class Planet : public Tile
	{
	private:
		unsigned char m_owner;	//example: 0-nobody, 1-first player, 2-second player

	
	public:
		Planet();

		unsigned char getOwner();
	};
}