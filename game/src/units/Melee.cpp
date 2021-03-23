#include "../../include/units/Melee.hpp"

namespace game
{
	Melee::Melee(game::ObjectType type,
		const sf::Texture& texture,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour)
		:
		IUnit{type, texture, moveSpeed, attackDamage, armour}
	{}
}