#include "../include/Tile.hpp"
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <iostream>


namespace engine
{
	Tile::Tile()
	{
		srand(time(NULL));
		shape.setSize(sf::Vector2f(10, 10));
		shape.setFillColor(sf::Color::Green);
		
	}
}
