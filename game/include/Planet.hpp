#pragma once
#include "Tile.hpp"
#include "Ownership.hpp"

namespace game
{
	class Planet : public Tile
	{
	private:
		Ownership m_owner;


	public:
		Planet();

		Ownership getOwner();
	};
}
