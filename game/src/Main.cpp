#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../engine/include/Map.hpp"
#include "Main.h"



int main()
{
	
	engine::Map map;
	srand(time(NULL));

	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Neumann Game");
 	sf::Texture texture;

	sf::View view1(sf::Vector2f(100.f, 100.f), sf::Vector2f(1280.f, 720.f));

	while (window.isOpen())
	{
		sf::Event event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		{
			view1.move(-1.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			view1.move(1.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			view1.move(0.f, -1.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			view1.move(0.f, 1.f);
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		for (int i = 0; i < map.mapsize; i++) {
			for (int j = 0; j < map.mapsize; j++) {
				if ((i + j) % 3 == 0) map.tile[i][j].shape.setFillColor(sf::Color::Red);
				map.tile[i][j].shape.setPosition(i*10, j*10);
				window.draw(map.tile[i][j].shape);
			}
		}
	

	
		window.setView(view1);
		window.display();
		
	}

	return 0;
}