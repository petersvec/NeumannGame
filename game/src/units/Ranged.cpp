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

	void Ranged::update(std::shared_ptr<engine::Map> map,
						engine::ObjectManager objMan,
						bool toUpdate,
						engine::UnitFactoryPtr unitFactory,
						PlayerState& playerState,
						ObjectType objType)
	{
		Ownership enemy = ((getOwner() == Ownership::Player1) ? Ownership::Player2 : Ownership::Player1);

		for (auto& i : objMan.getPlayerObjects())
		{
			if (i->getOwner() != enemy)
			{
				continue;
			}

			if (engine::TileDistance(getPosition(), i->getPosition()) <= getMoveSpeed())
			{
				attack(i);
			}
		}
	}

	void Ranged::attack(engine::IObjectPtr object)
	{
		if (object == nullptr)
		{
			return;
		}
		object->setHp(object->getHp() - getAttackDamage() / 2);
	}
	std::string Ranged::getName()
	{
		return "Ranged";
	}
	
}