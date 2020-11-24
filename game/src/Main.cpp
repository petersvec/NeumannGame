#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../engine/include/Map.hpp"
#include "Main.h"



int main()
{
	
	engine::Map map;
	srand(time(NULL));
	
	sf::VertexArray rectangles(sf::Quads);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Neumann Game");
	sf::View view1(sf::Vector2f(100.f, 100.f), sf::Vector2f(1280.f, 720.f));
	int TileSize = 10;
	float ZoomLevel = 1;


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
			else if (event.type == sf::Event::MouseWheelMoved)
			{
				
				view1.zoom(1 + 0.1*event.mouseWheel.delta);
				ZoomLevel += 1 + 0.1 * event.mouseWheel.delta);
				
			}
		}

		window.clear(sf::Color::Black);
		sf::Color TileCol;
		for (int i = 0; i < map.mapsize; i++) {
			for (int j = 0; j < map.mapsize; j++) {
			//	if ((i + j) % 3 == 0) map.tile[i][j].shape.setFillColor(sf::Color::Red);
				if ((i + j) % 3 == 0) TileCol = sf::Color::Red;
				else TileCol = sf::Color::Green;
				rectangles.append(sf::Vertex(sf::Vector2f(i*TileSize, j*TileSize), TileCol));
				rectangles.append(sf::Vertex(sf::Vector2f(i*TileSize + TileSize, j*TileSize), TileCol));
				rectangles.append(sf::Vertex(sf::Vector2f(i* TileSize + TileSize, j* TileSize + TileSize), TileCol));
				rectangles.append(sf::Vertex(sf::Vector2f(i* TileSize, j* TileSize + TileSize), TileCol));
					
				
//				map.tile[i][j].shape.setPosition(i*10, j*10);
//				map.tile[i][j].shape;
				
			}
		}

		
		window.draw(rectangles);
		window.setView(view1);
		window.display();
		rectangles.clear();
		
	}

	return 0;
}