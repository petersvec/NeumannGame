#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

namespace engine
{
	class Tile {
	public:
		Tile();
		Tile(int tilesize);
		//int value;
		//sf::Texture texture;
		sf::RectangleShape shape;
		//sf::Color color;
	private:
	};
}