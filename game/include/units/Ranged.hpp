#pragma once
#include "IUnit.hpp"

namespace game
{
	class Ranged : public IUnit
	{
	private:

	protected:

	public:
		Ranged(game::ObjectType type,
			const sf::Texture& texture,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour);
	};
}