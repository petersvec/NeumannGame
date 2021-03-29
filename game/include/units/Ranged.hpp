#pragma once
#include <memory>
#include "IUnit.hpp"
using TilePtr = std::shared_ptr<game::Tile>;

namespace game
{
	class Ranged : public IUnit
	{
	private:

	protected:

	public:
		Ranged(game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour);
	};
}