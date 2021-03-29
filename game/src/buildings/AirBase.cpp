#include "../../include/buildings/AirBase.hpp"

namespace game
{
	AirBase::AirBase(game::ObjectType type,
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