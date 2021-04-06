#include "../../include/units/Melee.hpp"

namespace game
{
	Melee::Melee(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
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

	void Melee::move(engine::TilePtr tile)
	{
		unsigned short x1 = tile->getPosition().x;
		unsigned short y1 = tile->getPosition().y;
		unsigned short x2 = getLocation()->getPosition().x;
		unsigned short y2 = getLocation()->getPosition().y;

		if (getMoveSpeed() <= sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))
		{
			setPosition(engine::ScreenToTile(tile->getPosition()));
		}
	}
}