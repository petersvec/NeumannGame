#include "../../include/units/Ranged.hpp"

namespace game
{
	Ranged::Ranged(unsigned short hp,
				   ObjectType type,
				   const sf::Texture& texture,
				   engine::TilePtr location,
				   unsigned char moveSpeed,
				   unsigned char attackDamage,
				   unsigned char armour,
				   Ownership owner)
				   :
			 	   IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner },
				   IObject{ hp, type, texture, location, owner }
	{}

	void Ranged::attack(std::shared_ptr<engine::IObject> object, std::shared_ptr<engine::ObjectManager> objMan)
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
			objMan->removeUnit(object);
		}
	}

	std::string Ranged::getName()
	{
		return "Ranged";
	}
}