#include "../../include/buildings/MilitaryBase.hpp"

namespace game
{
	MilitaryBase::MilitaryBase(game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ type, texture, location, ironCost, copperCost, siliconCost },
		IObject{ type, texture, location }
	{}
}