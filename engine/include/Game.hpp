#pragma once
#include <SFML/Graphics.hpp>
#include "../include/MapGenerator.hpp"

namespace engine
{
	class Game
	{
	private:
		//Private variables
		//Window
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event event;
		MapGenerator mapGen;

		sf::RectangleShape tile;

		//Private functions
		void initVariables();
		void initWindow();
		void initTiles();
		void initTile(size_t i, size_t j);

	public:
		//Constructors & destructor
		Game();
		virtual ~Game();

		//Accessors
		const bool isRunning() const;

		//Public functions
		void pollEvents();
		void update();
		void render();
	};
}