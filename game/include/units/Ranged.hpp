#pragma once
#include "IUnit.hpp"

namespace game
{
	class Ranged : public IUnit
	{
	private:

	protected:

	public:
		Ranged(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			game::Ownership owner);

		virtual void attack(engine::IObjectPtr object);
		virtual void move(engine::TilePtr tile, unsigned char tileSize);
	};
}