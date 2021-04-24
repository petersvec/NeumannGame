#include "../../include/units/Melee.hpp"

namespace game
{
	Melee::Melee(unsigned short hp,
				 ObjectType type,
				 const sf::Texture& texture,
				 engine::TilePtr location,
				 unsigned char moveSpeed,
				 unsigned char range,
				 unsigned char attackDamage,
				 unsigned char armour,
				 Ownership owner)
				 :
				 IUnit{ hp, type, texture, location, moveSpeed, range, attackDamage, armour, owner },
				 IObject{ hp, type, texture, location, owner }
	{}

	void Melee::attack(std::shared_ptr<engine::IObject> object, std::shared_ptr<engine::ObjectManager> objMan)
	{
		if (object == nullptr)
		{
			return;
		}

		if (engine::TileDistance(getPosition(), object->getPosition()) > getRange())
		{
			return;
		}

		if (object->getType() == ObjectType::Ranged)
		{
			if (object->getHp() > getAttackDamage() * 2)
			{
				object->setHp(object->getHp() - (getAttackDamage() * 2));
			}
			else
			{
				objMan->removeUnit(object);
			}
		}
		else
		{
			if (object->getHp() > getAttackDamage())
			{
				object->setHp(object->getHp() - getAttackDamage());
			}
			else
			{
				objMan->removeUnit(object);
			}
		}
	}

	std::string Melee::getName()
	{
		return "Melee";
	}
}