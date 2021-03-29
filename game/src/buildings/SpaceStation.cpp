#include "../../include/buildings/SpaceStation.hpp"

namespace game
{
	SpaceStation::SpaceStation(game::ObjectType type,
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