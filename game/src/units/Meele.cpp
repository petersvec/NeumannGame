#include "../../include/units/Meele.hpp"

namespace game
{
	Meele::Meele(game::ObjectType type, const sf::Texture& texture, unsigned char moveSpeed, unsigned char attackDamage, unsigned char armour)
		:
		IUnit{type, texture, moveSpeed, attackDamage, armour}
	{

	}
}