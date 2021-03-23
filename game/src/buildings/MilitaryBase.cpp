#include "../../include/buildings/MilitaryBase.hpp"

namespace game
{
	MilitaryBase::MilitaryBase(game::ObjectType type,
		const sf::Texture& texture,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{type, texture, ironCost, copperCost, siliconCost}
	{}
}