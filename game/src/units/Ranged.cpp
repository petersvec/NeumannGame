#include "../../include/units/Ranged.hpp"

namespace game
{
	Ranged::Ranged(game::ObjectType type,
		const sf::Texture& texture,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour)
		:
		IUnit{ type, texture, moveSpeed, attackDamage, armour }
	{}
}