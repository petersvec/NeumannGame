#include "../../include/units/Melee.hpp"

namespace game
{
	Melee::Melee(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		Player owner)
		:
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner },
		IObject{ hp, type, texture, location, owner }
	{}

	void Melee::attack(engine::IObjectPtr object)
	{
		if (object->getType() == game::ObjectType::Ranged)
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