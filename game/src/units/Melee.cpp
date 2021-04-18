#include "../../include/units/Melee.hpp"

namespace game
{
	Melee::Melee(unsigned short hp,
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

	void Melee::update(std::shared_ptr<engine::Map> map,
					   std::shared_ptr<engine::ObjectManager> objMan,
					   bool toUpdate,
					   PlayerState& playerState,
					   ObjectType objType)
	{
		Ownership enemy = ((getOwner() == Ownership::Player1) ? Ownership::Player2 : Ownership::Player1);
		attack(objMan->findUnit(getPosition().x, getPosition().y, enemy));
	}

	void Melee::attack(engine::IObjectPtr object)
	{
		if (object == nullptr)
		{
			return;
		}

		if (engine::TileDistance(getPosition(), object->getPosition()) > getMoveSpeed())
		{
			return;
		}

		if (object->getType() == ObjectType::Ranged)
		{
			object->setHp(object->getHp() - (getAttackDamage() * 2));
		}
		else
		{
			object->setHp(object->getHp() - getAttackDamage());
		}
	}
	std::string Melee::getName()
	{
		return "Melee";
	}
	
}