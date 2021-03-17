#pragma once
#include "IUnit.hpp"

namespace game
{
	class Meele : public IUnit
	{
	private:

	protected:

	public:
		Meele(game::ObjectType type, const sf::Texture& texture, unsigned char moveSpeed, unsigned char attackDamage, unsigned char armour);
	};
}