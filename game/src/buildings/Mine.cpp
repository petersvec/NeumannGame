#include "../../include/buildings/Mine.hpp"

namespace game
{
	Mine::Mine(game::ObjectType type,
		const sf::Texture& texture,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ type, texture, ironCost, copperCost, siliconCost }
	{}
}