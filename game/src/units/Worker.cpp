#include "../../include/units/Worker.hpp"

namespace game
{
	Worker::Worker(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour)
		:
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour },
		engine::IObject{ hp, type, texture, location }
	{}

	void Worker::attack(engine::IObject object)
	{
		object.setHp(object.getHp() - getAttackDamage());
	}
}