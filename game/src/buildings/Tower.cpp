#include "../../include/buildings/Tower.hpp"

namespace game
{
	Tower::Tower(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost },
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour },
		IObject{ hp, type, texture, location }
	{}

	void Tower::attack(engine::IObject object)
	{
		object.setHp(object.getHp() - getAttackDamage());
	}
}