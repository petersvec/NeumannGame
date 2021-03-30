#pragma once
#include "IUnit.hpp"

namespace game
{
	class Probe : public IUnit
	{
	private:

	protected:

	public:
		Probe(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour);

		virtual void attack(engine::IObject object);
	};
}