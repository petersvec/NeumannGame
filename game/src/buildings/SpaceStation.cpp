#include "../../include/buildings/SpaceStation.hpp"

namespace game
{
	SpaceStation::SpaceStation(game::ObjectType type,
		const sf::Texture& texture,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ type, texture, ironCost, copperCost, siliconCost }
	{}
}