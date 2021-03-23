#pragma once
#include "IBuilding.hpp"

namespace game
{
	class MilitaryBase : public IBuilding
	{
	private:

	protected:

	public:
		MilitaryBase(game::ObjectType type,
			const sf::Texture& texture,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost);
	};
}