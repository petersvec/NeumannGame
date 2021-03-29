#pragma once
#include "IUnit.hpp"

namespace game
{
	class Worker : public IUnit
	{
	private:

	protected:

	public:
		Worker(game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour);
	};
}