#include "../../include/units/Probe.hpp"

namespace game
{
	Probe::Probe(unsigned short hp,
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

	void Probe::attack(engine::IObjectPtr object)
	{
		object->setHp(object->getHp() - getAttackDamage());
	}

	void Probe::move(engine::TilePtr tile)
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