#include "../../include/buildings/Tower.hpp"

namespace game
{
	Tower::Tower(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost,
		game::Ownership owner)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner },
		IObject{ hp, type, texture, location, owner }
	{}

	void Tower::attack(engine::IObjectPtr object)
	{
		object->setHp(object->getHp() - getAttackDamage());
	}

	void Tower::update(std::shared_ptr<engine::Map> map,
					   engine::ObjectManager objMan,
					   bool toUpdate,
					   engine::UnitFactoryPtr unitFactory,
					   game::PlayerState playerState1)
	{
		std::pair<unsigned short, unsigned short> xyLocation = map->getTileXY(getLocation());
		std::vector<std::pair<unsigned short, unsigned short>> allTilesToApplyDamage;
		Ownership owner = ((getOwner() == Ownership::Player1) ? Ownership::Player2 : Ownership::Player2);

		if (xyLocation.first == engine::G_MAX_MAP_SIZE || xyLocation.second == engine::G_MAX_MAP_SIZE)
		{
			return;
		}

		for (unsigned short i = xyLocation.first - ((getMoveSpeed() / 5) / 2); i < xyLocation.first + ((getMoveSpeed() / 5) / 2); ++i)
		{
			if (i < 0 || i >= map->getHeight())
			{
				continue;
			}
			for (unsigned short j = xyLocation.first - ((getMoveSpeed() / 5) / 2); j < xyLocation.first + ((getMoveSpeed() / 5) / 2); ++j)
			{
				if (j < 0 || j >= map->getWidth())
				{
					continue;
				}

				attack(objMan.findUnit(i, j, owner));
			}
		}
	}
}