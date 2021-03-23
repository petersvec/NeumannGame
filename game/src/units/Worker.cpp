#include "../../include/units/Worker.hpp"

namespace game
{
	Worker::Worker(game::ObjectType type,
		const sf::Texture& texture,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour)
		:
		IUnit{ type, texture, moveSpeed, attackDamage, armour }, IObject{ type, texture }
	{}
}