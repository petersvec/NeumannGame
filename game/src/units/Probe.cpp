#include "../../include/units/Probe.hpp"

namespace game
{
	Probe::Probe(game::ObjectType type,
		const sf::Texture& texture,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour)
		:
		IUnit{ type, texture, moveSpeed, attackDamage, armour }, IObject{ type, texture }
	{}
}