#pragma once
#include "IUnit.hpp"

namespace game
{
	class Melee : public IUnit
	{
	private:

	protected:

	public:
		Melee(game::ObjectType type, const sf::Texture& texture, unsigned char moveSpeed, unsigned char attackDamage, unsigned char armour);
	};
}