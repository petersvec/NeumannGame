#pragma once
#include "../../engine/include/IObject.hpp"
#include "TileType.hpp"

namespace game
{
	class Tile
	{
	private:

	protected:
		TileType m_type;
		sf::Sprite m_sprite;

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
	};
}