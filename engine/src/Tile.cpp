#include "../include/Tile.hpp"
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <iostream>


namespace engine
{
	Tile::Tile()
	{
		srand(time(NULL));
		shape.setSize(sf::Vector2f(100, 100));
		//	shape.setFillColor(sf::Color::Green);
		//color = sf::Color::Green;

	}
	Tile::Tile(int tilesize)
	{	
		srand(time(NULL));
		shape.setSize(sf::Vector2f(tilesize, tilesize));
		//	shape.setFillColor(sf::Color::Green);
		//color = sf::Color::Green;

	}
}
