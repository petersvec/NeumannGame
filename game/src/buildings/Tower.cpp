#include "../../include/buildings/Tower.hpp"
#include "../../include/units/Probe.hpp"

namespace game
{
	Tower::Tower(unsigned short hp,
				 ObjectType type,
				 const sf::Texture& texture,
				 engine::TilePtr location,
				 unsigned char moveSpeed,
				 unsigned char range,
				 unsigned char attackDamage,
				 unsigned char armour,
				 unsigned short ironCost,
				 unsigned short copperCost,
				 unsigned short siliconCost,
				 Ownership owner)
				 :
				 IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
				 IUnit{ hp, type, texture, location, moveSpeed, range, attackDamage, armour, owner },
				 IObject{ hp, type, texture, location, owner }
	{}

	void Tower::update(std::shared_ptr<engine::Map> map,
					   std::shared_ptr<engine::ObjectManager> objMan,
					   bool toUpdate,
					   PlayerState& playerState)
	{
		Ownership enemy = ((getOwner() == Ownership::Player1) ? Ownership::Player2 : Ownership::Player1);

		for (auto& i : objMan->getPlayerObjects())
		{
			if (i->getOwner() != enemy)
			{
				continue;
			}

			if (engine::TileDistance(getPosition(), i->getPosition()) <= getRange())
			{
				attack(i, objMan);
			}
		}
	}

	void Tower::attack(std::shared_ptr<engine::IObject> object, std::shared_ptr<engine::ObjectManager> objMan)
	{
		if (object == nullptr)
		{
			return;
		}

		if (object->getHp() > getAttackDamage())
		{
			object->setHp(object->getHp() - getAttackDamage());
		}
		else
		{
			if (object->getType() == ObjectType::Probe)
			{
				auto probe = dynamic_cast<Probe*>(object.get());

				if (probe->isLoaded())
				{
					objMan->removeLoadedUnit(probe->getTroop());
				}
			}

			objMan->removeUnit(object);
		}
	}
  
	std::string Tower::getName()
	{
		return "Tower";
	}
}