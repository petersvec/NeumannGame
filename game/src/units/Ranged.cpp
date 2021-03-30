#include "../../include/units/Ranged.hpp"

namespace game
{
	Ranged::Ranged(unsigned short hp,
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

	void Ranged::attack(engine::IObject object)
	{
		object.setHp(object.getHp() - getAttackDamage() / 2);
	}
}