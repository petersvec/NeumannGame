#include "../../include/buildings/Tower.hpp"

namespace game
{
	Tower::Tower(game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ type, texture, location, ironCost, copperCost, siliconCost },
		IUnit{ type, texture, location, moveSpeed, attackDamage, armour },
		IObject{ type, texture, location }
	{}
}