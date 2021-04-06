#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "TileType.hpp"
#include "Ownership.hpp"

namespace game
{
	class Tile
	{
	private:

	protected:
		TileType m_type;
		sf::Sprite m_sprite;
		game::Ownership m_occupied;

	public:
		Tile();
		Tile(unsigned char type);

		Tile operator = (const unsigned char);
		bool operator == (const unsigned char);

		unsigned char getType();
		sf::Sprite getSprite();
		sf::Vector2f getPosition() const;

		void setType(unsigned char type);
		void setSprite(const sf::Texture& texture);
		void setPosition(float, float);
		game::Ownership getOccupied();
		void setOccupied(game::Ownership ownership);
	};
}