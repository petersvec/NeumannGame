#include "../../include/units/Probe.hpp"

namespace game
{
	Probe::Probe(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		Player owner)
		:
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner },
		IObject{ hp, type, texture, location }
	{}

	void Probe::attack(engine::IObject object)
	{
		object.setHp(object.getHp() - getAttackDamage());
	}
}