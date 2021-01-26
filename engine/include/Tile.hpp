#pragma once
#include <SFML\Graphics\Sprite.hpp>

namespace engine
{
	class Tile
	{
	private:
		unsigned char m_type;	//type of the Tile: 0-void, 1-planet of player one, 2-planet of player 2, 3-resources on the planet, 4-resources on the planet of the player 1, 5-resources on the planet of the player 2
		sf::Sprite m_sprite;

	public:
		Tile();
		Tile(unsigned char type);

		Tile operator = (const unsigned char type);
		bool operator == (const unsigned char type);

		unsigned char getType();
		sf::Sprite getSprite();
	};
}