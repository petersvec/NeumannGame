#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "TileType.hpp"

namespace game
{
	class Tile
	{
	private:

	protected:
		TileType m_type;
		sf::Sprite m_sprite;
		bool occupied = 0;

	public:
		Tile();
		Tile(unsigned char type);

		Tile operator = (const unsigned char);
		bool operator == (const unsigned char);

		unsigned char getType();
		sf::Sprite getSprite();

		void setType(unsigned char type);
		void setSprite(const sf::Texture& texture);
		void setPosition(float, float);
		bool getOccupied();
		void setOccupied(bool value);
	};
}