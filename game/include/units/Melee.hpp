#pragma once
#include "IUnit.hpp"

namespace game
{
	class Melee : public IUnit
	{
	private:

	protected:

	public:
		Melee(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			Player owner);

		virtual void attack(engine::IObjectPtr object);
		virtual void move(engine::TilePtr tile);
	};
}