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
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost);
	};
}