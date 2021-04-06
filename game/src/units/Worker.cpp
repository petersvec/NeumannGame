#include "../../include/units/Worker.hpp"

namespace game
{
	Worker::Worker(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		game::Ownership owner)
		:
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner},
		engine::IObject{ hp, type, texture, location, owner }
	{}

	void Worker::attack(engine::IObjectPtr object)
	{
		object->setHp(object->getHp() - getAttackDamage());
	}

	void Worker::move(engine::TilePtr tile, unsigned char tileSize)
	{
		unsigned short x1 = tile->getPosition().x;
		unsigned short y1 = tile->getPosition().y;
		unsigned short x2 = getLocation()->getPosition().x;
		unsigned short y2 = getLocation()->getPosition().y;

		//kontrola ci sa moze pohybovat
		if (getMoveSpeed() <= (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / tileSize))
		{
			setPosition(engine::ScreenToTile(tile->getPosition()));

			//occupy new tile
			tile->setOccupied(getOwner());
		}
	}
}