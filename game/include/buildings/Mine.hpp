#pragma once
#include "IBuilding.hpp"

namespace game
{
	class Mine : public IBuilding
	{
	private:

	protected:

	public:
		Mine(game::ObjectType type,
			const sf::Texture& texture,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost);
	};
}