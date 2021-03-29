#pragma once
#include "IBuilding.hpp"

namespace game
{
	class SpaceStation : public IBuilding
	{
	private:

	protected:

	public:
		SpaceStation(game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost);
	};
}