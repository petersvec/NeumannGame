#include "../../include/buildings/Mine.hpp"

namespace game
{
	Mine::Mine(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost },
		IObject{ hp, type, texture, location }
	{}
}