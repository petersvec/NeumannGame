#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

namespace engine
{
	class Tile {
	public:
		Tile();
		Tile(int tilesize);
		sf::Sprite sprite;
		
	private:
	};
}