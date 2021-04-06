#include "../../include/units/Ranged.hpp"

namespace game
{
	Ranged::Ranged(unsigned short hp,
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

	void Ranged::attack(engine::IObjectPtr object)
	{
		object->setHp(object->getHp() - getAttackDamage() / 2);
	}

	void Ranged::move(engine::TilePtr tile, unsigned char tileSize)
	{
		unsigned short x1 = tile->getPosition().x;
		unsigned short y1 = tile->getPosition().y;
		unsigned short x2 = getLocation()->getPosition().x;
		unsigned short y2 = getLocation()->getPosition().y;

		if (getMoveSpeed() <= (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / tileSize))
		{
			setPosition(engine::ScreenToTile(tile->getPosition()));
		}
	}
}