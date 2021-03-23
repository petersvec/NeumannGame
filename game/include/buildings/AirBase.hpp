#pragma once
#include "IBuilding.hpp"

namespace game
{
	class AirBase : public IBuilding
	{
	private:

	protected:

	public:
		AirBase(game::ObjectType type,
			const sf::Texture& texture,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost);
	};
}