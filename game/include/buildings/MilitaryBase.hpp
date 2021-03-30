#pragma once
#include "IBuilding.hpp"

namespace game
{
	class MilitaryBase : public IBuilding
	{
	private:

	protected:

	public:
		MilitaryBase(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost);
	};
}