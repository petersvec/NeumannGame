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
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			Player owner);

		virtual void attack(engine::IObjectPtr object);
		virtual void move(engine::TilePtr tile, unsigned char tileSize);
	};
}