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

	void Tower::update(engine::Map map)
	{
		std::pair<unsigned short, unsigned short> xyLocation = map.getTileXY(getLocation());

		if (xyLocation.first == 10000 || xyLocation.second == 10000)
		{
			return;
		}

		for (unsigned short i = xyLocation.first - ((getMoveSpeed() / 5) / 2); i < xyLocation.first + ((getMoveSpeed() / 5) / 2); ++i)
		{
			if (i < 0 || i >= map.getHeight())
			{
				continue;
			}
			for (unsigned short j = xyLocation.first - ((getMoveSpeed() / 5) / 2); j < xyLocation.first + ((getMoveSpeed() / 5) / 2); ++j)
			{
				if (j < 0 || j >= map.getWidth())
				{
					continue;
				}
				
				//TODO: apply damage to objects on tile pointer map.getTile(i, j);
			}
		}
	}
}