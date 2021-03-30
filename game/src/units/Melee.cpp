#include "../../include/units/Melee.hpp"

namespace game
{
	Melee::Melee(unsigned short hp,
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