#include "../../include/buildings/Tower.hpp"

namespace game
{
	Tower::Tower(game::ObjectType type,
		const sf::Texture& texture,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ type, texture, ironCost, copperCost, siliconCost }, IUnit{ type, texture, moveSpeed, attackDamage, armour }, IObject{ type, texture }
	{}
}