#include "../../include/units/Ranged.hpp"

namespace game
{
	Ranged::Ranged(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour)
		:
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour },
		IObject{ hp, type, texture, location }
	{}
}