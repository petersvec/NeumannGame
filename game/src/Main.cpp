#include <SFML/Graphics.hpp>
#include "/Users/andre/Documents/Programovanie/Git/NeumannGame/engine/include/Game.hpp"

int main(void)
{
	//Init game engine
	Game game;
	//Window of the application
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Neumann Game", sf::Style::Titlebar | sf::Style::Close);

	//Game loop
	while (game.isRunning())
	{
		sf::Event event;

		//Event polling
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		//----------UPDATE----------//

		//----------RENDER----------//
		window.clear(sf::Color::Black);								//Clear old frame

		//Draw the game HERE


		window.display();											//Tell app that window is done drawing
	}
	//End of appliecation
	return 0;
}