#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

namespace engine
{
	class Tile {
	public:
		Tile();
		Tile(int tilesize);
		//int value;
		//sf::Texture* texture;
		sf::Sprite sprite;
		
	private:
	};
}