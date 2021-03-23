#pragma once
#include "IUnit.hpp"

namespace game
{
	class Probe : public IUnit
	{
	private:

	protected:

	public:
		Probe(game::ObjectType type,
			const sf::Texture& texture,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour);
	};
}